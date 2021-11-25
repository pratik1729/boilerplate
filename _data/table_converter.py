import sys
import os
import markdown
file_path = sys.argv[1]
mdfile = open(file_path,"r")
all_lines = mdfile.readlines()
sys.stderr = sys.stdout
sys.stdout = open(f"./../{os.path.basename(file_path)}", 'w')

def write_header(header):
    print("<table>")
    print("<tr>")
    for i in header:
        print(f"<th>{i}</th>")
    print("</tr>")
    
def write_row(row):
    print("<tr>")
    html_stag=""
    html_etag=""
    if row[0][0] == '#':
        html_stag = "<pre><code><pre>\n"
        html_etag = "</pre></code></pre>\n"
    else:
        html_stag = "<pre>\n"
        html_etag = "</pre>"      
    for i in row:
        html = markdown.markdown(i,extensions=['fenced_code'])
        print("<td>")
        print(html)
        
        print("</td>")
        # continue
        # if i[0] == '#':
        #     nl = i.index('\n')
        #     lang = i[1:nl] # code language
        #     lang = lang.split()[0]
        #     i = i[nl+1:]
        #     html_stag = f'<pre><code class="language-{lang}"><pre>\n'
        #     html_etag = "</pre></code></pre>\n"
            
        # else:
        #     html_stag = "<pre>\n"
        #     html_etag = "</pre>"
        # print("<td>",end="")
        # print(html_stag,end="")
        # print(i,end="")
        # print(html_etag,end="")
        # print("</td>")
    print("</tr>")
    
def clean_header(h):
    # delete new lines character
    h.pop(0)
    h.pop(-1)
    #remove all spaces
    for i,s in enumerate(h):
        h[i]=" ".join(s.split(" "))

def process_table(first, last):
    tab = all_lines[first:last+1]
    header = tab[0].split("|")
    clean_header(header)
    write_header(header)
    cols = len(header)
    row = [""]*cols
    for i,l in enumerate(tab[1:]):
        if l.startswith("| ---"):
            if row[0]:
                write_row(row)
                row = [""]*cols
            continue
       
        line = l.split('|')
        line.pop(0)
        line.pop(-1)
        for j in range(cols):
            line[j] = line[j][1:]
            line[j] = line[j].replace("⎮","|")
            row[j] = row[j]  + line[j] + '\n'

        if i==len(tab)-2:
            if row[0]:
                write_row(row)
                row = [""]*cols

def main():
    offset = 2
    table_tag = '[//]: # ("code table")'
    tab_first = 0
    tab_last = 0
    tag = 0
    if "markdown" not in sys.modules:
        sys.stderr.write("markdown module is not installed! \n")
        exit()

    for i,l in enumerate(all_lines):
        # start of a table is checked with the table tag
        if l.startswith(table_tag):
            assert all_lines[i+offset].startswith("|")
            tag = 1
            print(l,end="")
        # if tag detected, check | for start of actual MD table
        elif tag == 1 and l.startswith("|") and tab_first == 0:
            tab_first = i
        # after detecting tag and table start, check for end of table
        elif tag == 1 and (not l.startswith("|")) and tab_first:
            tab_last = i-1
            process_table(tab_first, tab_last)
            tag = 0
            tab_first = 0
            tab_last = 0
            print("</table>")
        elif not tag:
            print(l,end="")

if __name__=="__main__":
    main()