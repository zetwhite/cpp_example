---


---

<h1 id="copy-constructor">copy constructor</h1>
<p>객체가 함수 인자로 넘어가는 경우,<br>
개체 안에 pointer가 존재할 경우 포인터가 가르키는 값은 복사되지 않는 얕은복사(shallow copy)가 일어난다는 문제가 있다.<br>
따라서 해당 경우를 어떻게 처리할지 명시하는 함수가 <code>copy_constructor</code>이다.</p>
<ul>
<li>함수명은 class명과 동일, 매개변수가 자기가 속한 class type</li>
<li><code>className (const className&amp; )</code></li>
<li>같은 class의 다른 객체의 값을 바탕으로 새로운 객체를 초기화하는 함수(생성자)</li>
</ul>
<h3 id="implicit-copy-constructor">implicit copy constructor</h3>
<p>코드에 복사생성자가 명시되어 있지 않으면 컴파일러가 자동적으로 복사생성자를 생성한다.<br>
그렇기에 만약 내부에서 동적으로 메모리를 할당해주는 부분이 없다면, 굳이 복사생성자를 생성하지 않아도 된다.</p>
<ul>
<li>멤버변수 별로 값을 복사하여 대입해준다.</li>
<li>만약 멤버변수가 객체라면, 그 객체의 복사생성자를 호출하여 객체의 값을 초기화해준다.</li>
</ul>
<pre class=" language-cpp"><code class="prism  language-cpp"><span class="token keyword">class</span> <span class="token class-name">MyString</span><span class="token punctuation">{</span>
<span class="token keyword">private</span><span class="token operator">:</span>
	<span class="token keyword">int</span> capacity<span class="token punctuation">;</span>
	<span class="token keyword">int</span> length<span class="token punctuation">;</span>
	<span class="token keyword">char</span><span class="token operator">*</span> buffer<span class="token punctuation">;</span>
<span class="token keyword">public</span><span class="token operator">:</span>
	<span class="token function">MyString</span><span class="token punctuation">(</span><span class="token keyword">int</span> c <span class="token operator">=</span> <span class="token number">16</span><span class="token punctuation">)</span>
	<span class="token operator">:</span><span class="token function">capacity</span><span class="token punctuation">(</span>c<span class="token punctuation">)</span><span class="token punctuation">{</span><span class="token punctuation">}</span>
	<span class="token function">MyString</span><span class="token punctuation">(</span>MyString<span class="token operator">&amp;</span> other<span class="token punctuation">)</span>
	<span class="token operator">:</span><span class="token function">capacity</span><span class="token punctuation">(</span>other<span class="token punctuation">.</span>capacity<span class="token punctuation">)</span><span class="token punctuation">,</span> <span class="token function">length</span><span class="token punctuation">(</span>length<span class="token punctuation">)</span><span class="token punctuation">{</span>
		buffer <span class="token operator">=</span> <span class="token keyword">new</span> <span class="token keyword">char</span><span class="token punctuation">[</span>capacity<span class="token punctuation">]</span><span class="token punctuation">;</span>
		<span class="token keyword">for</span><span class="token punctuation">(</span><span class="token keyword">int</span> i <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span> i <span class="token operator">&lt;</span> length<span class="token punctuation">;</span> i<span class="token operator">++</span><span class="token punctuation">)</span>
			buffer<span class="token punctuation">[</span>i<span class="token punctuation">]</span> <span class="token operator">=</span> other<span class="token punctuation">.</span>buffer<span class="token punctuation">[</span>i<span class="token punctuation">]</span><span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
<span class="token punctuation">}</span><span class="token punctuation">;</span>
</code></pre>

