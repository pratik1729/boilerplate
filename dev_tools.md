---
layout: default
title: Dev Tools
---
# Dev Tools

# Valgrind

## Basic usage

### valgrind \--tool=[tool name] [tool options] [program] [program options]

## Tools

[//]: # ("code table")
<table>
<tr>
<th> Tool    </th>
<th> Options    </th>
<th> Description                                                                      </th>
</tr>
<tr>
<td>
<p>--tool= </p>
</td>
<td>
<p>memcheck   </p>
</td>
<td>
<p>memory error detector, memory leaks, invalid memory access                       </p>
</td>
</tr>
<tr>
<td>

</td>
<td>
<p>cachegrind </p>
</td>
<td>
<p>cache misses, miss rate                                                          </p>
</td>
</tr>
<tr>
<td>

</td>
<td>
<p>callgrind  </p>
</td>
<td>
<p>number of instructions executed, their relationship to source lines,           <br />
the caller/callee relationship between functions, and the numbers of such calls. </p>
</td>
</tr>
<tr>
<td>

</td>
<td>
<p>helgrind   </p>
</td>
<td>
<p>a thread error detector, detects synchronisation errors                          </p>
</td>
</tr>
<tr>
<td>

</td>
<td>
<p>drd        </p>
</td>
<td>
<p>a thread error detector                                                          </p>
</td>
</tr>
<tr>
<td>

</td>
<td>
<p>massif     </p>
</td>
<td>
<p>heap profiler. It measures how much heap memory your program uses.               </p>
</td>
</tr>
<tr>
<td>

</td>
<td>
<p>dhat       </p>
</td>
<td>
<p>a dynamic heap analysis tool                                                     </p>
</td>
</tr>
<tr>
<td>

</td>
<td>
<p>lackey     </p>
</td>
<td>
<p>various kinds of basic program measurement like number of function calls, etc    </p>
</td>
</tr>
<tr>
<td>

</td>
<td>
<p>exp-bbv    </p>
</td>
<td>
<p>an experimental basic block vector generation tool                               </p>
</td>
</tr>
</table>
# gcc

| Option        | Description          | Description    |
| ------------- | -------------------- | -------------- |
| -fsanitize=   | address              |                |
|               | undefined            |                |
|               | float-cast-overflow  |                |
|               | float-divide-by-zero |                |
| -Wall -Wextra |                      | Shows warnings |
|               |                      |                |
