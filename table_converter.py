import sys

header=[]
codelines=[]
head=0
def clean_header(h):
    h.pop(0)
    h.pop(-1)
    #remove all spaces
    for i,s in enumerate(h):
        h[i]=s.replace(" ","")

mdfile = open(sys.argv[1])

for l in mdfile:
    if l.startswith("[//]: #"):
        l=next(mdfile)
        l=next(mdfile)
        assert l[0]=='|'
        header=l.split('|')
        clean_header(header)
        cols = len(header)
        for c in range(cols):
            codelines.append("")
        # print(header)
        head=1
        l=next(mdfile)


    elif head == 1:
        if l[0] != '|' :
            break
        line = l.split('|')
        line.pop(0)
        line.pop(-1)
        for c in range(cols):
            codelines[c] = codelines[c] + '\n' + line[c]



print("<table>")
print("<tr>")
for h in header:
    print("<th>",end="")
    print(h,end="")
    print("</th>",end="")
    print()
print("</tr>")
print()
print("<tr>")
for h in codelines:
    print("<td>")
    print("<pre><code><pre>",end="")
    print(h)
    print("</pre></code></pre>")
    print("</td>")
print("</tr>")

print("</table>")

mdfile.close()