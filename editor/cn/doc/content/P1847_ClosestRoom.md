<p>一个酒店里有&nbsp;<code>n</code>&nbsp;个房间，这些房间用二维整数数组&nbsp;<code>rooms</code>&nbsp;表示，其中&nbsp;<code>rooms[i] = [roomId<sub>i</sub>, size<sub>i</sub>]</code>&nbsp;表示有一个房间号为&nbsp;<code>roomId<sub>i</sub></code>&nbsp;的房间且它的面积为&nbsp;<code>size<sub>i</sub></code>&nbsp;。每一个房间号&nbsp;<code>roomId<sub>i</sub></code>&nbsp;保证是 <strong>独一无二</strong>&nbsp;的。</p>

<p>同时给你 <code>k</code>&nbsp;个查询，用二维数组&nbsp;<code>queries</code>&nbsp;表示，其中&nbsp;<code>queries[j] = [preferred<sub>j</sub>, minSize<sub>j</sub>]</code>&nbsp;。第&nbsp;<code>j</code>&nbsp;个查询的答案是满足如下条件的房间&nbsp;<code>id</code>&nbsp;：</p>

<ul> 
 <li>房间的面积&nbsp;<b>至少</b>&nbsp;为&nbsp;<code>minSize<sub>j</sub></code>&nbsp;，且</li> 
 <li><code>abs(id - preferred<sub>j</sub>)</code>&nbsp;的值 <strong>最小</strong>&nbsp;，其中&nbsp;<code>abs(x)</code>&nbsp;是&nbsp;<code>x</code>&nbsp;的绝对值。</li> 
</ul>

<p>如果差的绝对值有 <strong>相等</strong>&nbsp;的，选择 <strong>最小</strong>&nbsp;的&nbsp;<code>id</code>&nbsp;。如果 <strong>没有满足条件的房间</strong>&nbsp;，答案为 <code>-1</code>&nbsp;。</p>

<p>请你返回长度为 <code>k</code>&nbsp;的数组&nbsp;<code>answer</code>&nbsp;，其中<em>&nbsp;</em><code>answer[j]</code>&nbsp;为第 <code>j</code>&nbsp;个查询的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
<b>输出：</b>[3,-1,3]
<strong>解释：</strong>查询的答案如下：
查询 [3,1] ：房间 3 的面积为 2 ，大于等于 1 ，且号码是最接近 3 的，为 abs(3 - 3) = 0 ，所以答案为 3 。
查询 [3,3] ：没有房间的面积至少为 3 ，所以答案为 -1 。
查询 [5,2] ：房间 3 的面积为 2 ，大于等于 2 ，且号码是最接近 5 的，为 abs(3 - 5) = 2 ，所以答案为 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], queries = [[2,3],[2,4],[2,5]]
<b>输出：</b>[2,1,3]
<strong>解释：</strong>查询的答案如下：
查询 [2,3] ：房间 2 的面积为 3 ，大于等于 3 ，且号码是最接近的，为 abs(2 - 2) = 0 ，所以答案为 2 。
查询 [2,4] ：房间 1 和 3 的面积都至少为 4 ，答案为 1 因为它房间编号更小。
查询 [2,5] ：房间 3 是唯一面积大于等于 5 的，所以答案为 3 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul> 
 <li><code>n == rooms.length</code></li> 
 <li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li> 
 <li><code>k == queries.length</code></li> 
 <li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li> 
 <li><code>1 &lt;= roomId<sub>i</sub>, preferred<sub>j</sub> &lt;= 10<sup>7</sup></code></li> 
 <li><code>1 &lt;= size<sub>i</sub>, minSize<sub>j</sub> &lt;= 10<sup>7</sup></code></li> 
</ul>

<div><div>Related Topics</div><div><li>数组</li><li>二分查找</li><li>排序</li></div></div><br><div><li>👍 38</li><li>👎 0</li></div>