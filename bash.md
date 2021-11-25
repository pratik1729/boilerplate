---
layout: default
title: BASH
---
# BASH

# Loops

## For loop

[//]: # ("code table")
<table>
<tr>
<th> Basic for                        </th>
<th> C-like for                            </th>
<th> Ranges                  </th>
</tr>
<tr>
<td>
<pre><code class="language-bash">for i in [ls | /dir1/dir2/*]; do 
echo $i                          
done                             
</code></pre>
</td>
<td>
<pre><code class="language-bash">for i in ((i = 0 ; i &lt; 10 ; i++)); do 
echo $i                               
done                                  
</code></pre>
</td>
<td>
<pre><code class="language-bash">for i in {5..50..5}; do 
echo $i                 
done                    
</code></pre>
</td>
</tr>
</table>
## While loop

[//]: # ("code table")
<table>
<tr>
<th> while          </th>
<th> While infinite oneline        </th>
</tr>
<tr>
<td>
<pre><code class="language-bash">while true; do 
</code></pre>
</td>
<td>
<pre><code class="language-bash">while true; kill -9 420; done 
</code></pre>
</td>
</tr>
</table>
# Conditionals

[//]: # ("code table")
<table>
<tr>
<th> Compare strings                   </th>
<th> Check if string is empty(-z) or not(-n) </th>
<th> Compare numerics             </th>
</tr>
<tr>
<td>
<pre><code class="language-bash">if [[ &quot;$str1&quot; == &quot;$str2&quot; ]]; then 
</code></pre>
</td>
<td>
<pre><code class="language-bash">if [[ -z &quot;$string&quot; ]]; then             
echo &quot;empty&quot;                            
elif [[ -n &quot;$string&quot; ]]; then           
echo &quot;not empty&quot;                        
else                                    
echo &quot;This is to show if structure&quot;     
fi                                      
</code></pre>
</td>
<td>
<pre><code class="language-bash">if (( $n &lt; $m )); then       
echo &quot;$n is smaller than $m&quot; 
fi                           
</code></pre>
</td>
</tr>
</table>
# Arrays

## Basic operations

[//]: # ("code table")
<table>
<tr>
<th> Define arrays. Element accessed via indexing - arr[0] </th>
<th> Iterate over an array    </th>
</tr>
<tr>
<td>
<pre><code class="language-bash">arr=(a0 a1 a2)                                        


</code></pre>
</td>
<td>
<pre><code class="language-bash">for i in &quot;${arr[@]}&quot;; do 
echo $i                  
done                     
</code></pre>
</td>
</tr>
</table>
## Advanced

[//]: # ("code table")
<table>
<tr>
<th> Access last element </th>
<th> All elements, space separated </th>
<th> Number of elements </th>
<th> Get element at Nth position </th>
<th> Get subarray from position m and length n </th>
<th> Get keys of all elements, space separated, for dicts </th>
</tr>
<tr>
<td>
<pre><code class="language-bash">echo ${arr[-1]}     
</code></pre>
</td>
<td>
<pre><code class="language-bash">echo ${arr[@]}                
</code></pre>
</td>
<td>
<pre><code class="language-bash">echo ${#arr[@]}    
</code></pre>
</td>
<td>
<pre><code class="language-bash">echo ${arr[N]}             
</code></pre>
</td>
<td>
<pre><code class="language-bash">echo ${arr[@]:m:n}                        
</code></pre>
</td>
<td>
<pre><code class="language-bash">echo ${!arr[@]}                                      
</code></pre>
</td>
</tr>
</table>
# Numerics

Numerical Calculations are written in $((...)).

[//]: # ("code table")
<table>
<tr>
<th> Calculations </th>
<th> Generate random numbers 0..N </th>
</tr>
<tr>
<td>
<pre><code class="language-bash">$((a+b))     
</code></pre>
</td>
<td>
<pre><code class="language-bash">$(($RANDOM%N))               
</code></pre>
</td>
</tr>
</table>
# Special variables

| Number of arguments | All positional arguments (as a single word) | All positional arguments (as separate strings) | Nth positional arguments(0=filename of the script) | Exit status of last task | PID of last background task | PID of shell |
| ------------------- | ------------------------------------------- | ---------------------------------------------- | -------------------------------------------------- | ------------------------ | --------------------------- | ------------ |
| $#                  | $*                                          | $@                                             | $N                                                 | $?                       | $!                          | $$           |

# Redirection

[//]: # ("code table")
<table>
<tr>
<th> stdout to file       </th>
<th> stdout to file append   </th>
<th> stderr to file        </th>
<th> stderr to stdout </th>
<th> stderr to null        </th>
<th> stdout&stderr to null </th>
<th> feed file into stdin </th>
</tr>
<tr>
<td>
<p>./a.out &gt; file.txt </p>
</td>
<td>
<p>./a.out &gt;&gt; file.txt </p>
</td>
<td>
<p>./a.out 2&gt; file.txt </p>
</td>
<td>
<p>./a.out 2&gt;&amp;1   </p>
</td>
<td>
<p>./a.out 2&gt;/dev/null </p>
</td>
<td>
<p>./a.out &amp;&gt;/dev/null </p>
</td>
<td>
<p>./a.out &lt; file.txt </p>
</td>
</tr>
</table>
<p>
bash is used for interactive scripts execution and dash is for non-interactive scripts.<br>
/bin/sh is link to dash binary. dash is much faster than bash.<br>
dash is useful when redirection with sudo does not work, e.g.<br>
sudo echo 0 > file_owned_by_root, fails<br>
sudo sh -c 'echo 0 > file_owned_by_root'<br>
single quotes are Important.
</p>