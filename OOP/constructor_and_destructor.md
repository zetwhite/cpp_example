
<h1 id="access-modifier">Access Modifier</h1>
<p>class 멤버 함수와 변수에 대하여 접근을 제어할 수 있는 접근제어자가 존재한다.<br>
따로 표시를 하지 않으면, private로 선언된다.<br>
일반적으로 public 멤버를 먼저 class에 적은 후, 아래에 private 멤버를 작성한다.</p>
<ul>
<li>public: 다른 클래스의 함수, 전역함수 등 어디서나 접근 가능.</li>
<li>protected: 해당 클래스 내부의 method나 상속받은 자식 클래서만 접근이 가능.</li>
<li>private: 오직 클래스(개체가 아니다!!) 내부 method와 freind 함수에서 접근 가능. (같은 class라면 객체가 달라도 private member에 접근 가능하다.)</li>
</ul>
<pre class=" language-cpp"><code class="prism  language-cpp"><span class="token keyword">class</span> <span class="token class-name">Vector</span><span class="token punctuation">{</span>
<span class="token keyword">public</span><span class="token operator">:</span>
	<span class="token function">Vector</span><span class="token punctuation">(</span><span class="token keyword">int</span> _x <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">,</span> <span class="token keyword">int</span> _y <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">)</span><span class="token operator">:</span>
		<span class="token function">x</span><span class="token punctuation">(</span>_x<span class="token punctuation">)</span><span class="token punctuation">,</span>
		<span class="token function">y</span><span class="token punctuation">(</span>_y<span class="token punctuation">)</span><span class="token punctuation">{</span><span class="token punctuation">}</span>
	Vector <span class="token function">addVector</span><span class="token punctuation">(</span><span class="token keyword">const</span> Vector<span class="token operator">&amp;</span> another<span class="token punctuation">)</span><span class="token punctuation">{</span>
		Vector <span class="token function">newVector</span><span class="token punctuation">(</span>x <span class="token operator">+</span> another<span class="token punctuation">.</span>x<span class="token punctuation">,</span> y <span class="token operator">+</span> another<span class="token punctuation">.</span>y<span class="token punctuation">)</span><span class="token punctuation">;</span>
		<span class="token keyword">return</span> newVector<span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
<span class="token keyword">private</span><span class="token operator">:</span>
	<span class="token keyword">int</span> x<span class="token punctuation">;</span>
	<span class="token keyword">int</span> y<span class="token punctuation">;</span>
<span class="token punctuation">}</span><span class="token punctuation">;</span>
</code></pre>
<h1 id="new--delete">new , delete</h1>
<p>객체를 heap에 생성할지 stack에 생성할지 프로그래머가 정할 수 있다.</p>
<pre class=" language-cpp"><code class="prism  language-cpp">Vector <span class="token function">v1</span><span class="token punctuation">(</span><span class="token number">1</span><span class="token punctuation">,</span><span class="token number">2</span><span class="token punctuation">)</span><span class="token punctuation">;</span> <span class="token comment">//stack에 생성</span>

Vector<span class="token operator">*</span> v2 <span class="token operator">=</span> <span class="token keyword">new</span> <span class="token function">Vector</span><span class="token punctuation">(</span><span class="token number">1</span><span class="token punctuation">,</span><span class="token number">2</span><span class="token punctuation">)</span><span class="token punctuation">;</span> <span class="token comment">//heap에 생성</span>
<span class="token keyword">delete</span> v2<span class="token punctuation">;</span>
</code></pre>
<p><code>new</code>로 배열을 할당할 경우, <code>delete[]</code>를 사용해서 해제해야한다.</p>
<pre class=" language-cpp"><code class="prism  language-cpp">Vector<span class="token operator">*</span> list <span class="token operator">=</span> <span class="token keyword">new</span> Vector<span class="token punctuation">[</span><span class="token number">10</span><span class="token punctuation">]</span><span class="token punctuation">;</span>
<span class="token keyword">delete</span><span class="token punctuation">[</span><span class="token punctuation">]</span> list<span class="token punctuation">;</span>
list <span class="token operator">=</span> <span class="token constant">NULL</span><span class="token punctuation">;</span>
</code></pre>
<p>이렇게 delete[]를 사용하면 list[0] ~ list[10], 각각의 객체에 대하여 소멸자를 호출해준다.<br>
<a href="https://en.cppreference.com/w/cpp/language/raii">+) RAII : Resource Acquisition Is Initialization /link</a></p>
<h1 id="constructor">Constructor</h1>
<p>JAVA와 달리 자동으로 멤버변수를 초기화해주지 않는다.<br>
따라서 변수를 초기화해주지 않으면, 변수에는 쓰레기 값이 들어있다.<br>
Class이름과 같은 이름으로 생성자를 만들어서 멤버변수값을 설정할 수 있다.</p>
<ul>
<li>멤버변수의 초기화는 일반적으로 <code>initializer List</code>를 이용한다.<br>
<code>initializer List</code>를 이용하면 const 변수나 reference변수를 초기화할 수 있다.</li>
<li>다른 함수와 마찬가지로 오버로딩이 가능하다. 단, 이때 인자의 갯수나 자로형은 달라야한다.</li>
</ul>
<pre class=" language-cpp"><code class="prism  language-cpp"><span class="token keyword">class</span> <span class="token class-name">Test</span><span class="token punctuation">{</span>
<span class="token keyword">public</span><span class="token operator">:</span>
    <span class="token function">Test</span><span class="token punctuation">(</span><span class="token keyword">int</span> _n<span class="token punctuation">)</span><span class="token operator">:</span>
        <span class="token function">n</span><span class="token punctuation">(</span>_n<span class="token punctuation">)</span><span class="token punctuation">,</span> <span class="token function">max</span><span class="token punctuation">(</span><span class="token number">10000</span><span class="token punctuation">)</span><span class="token punctuation">{</span><span class="token punctuation">}</span>
    <span class="token function">Test</span><span class="token punctuation">(</span><span class="token keyword">int</span> _max<span class="token punctuation">)</span><span class="token operator">:</span>
        <span class="token function">n</span><span class="token punctuation">(</span><span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">,</span> <span class="token function">max</span><span class="token punctuation">(</span>_max<span class="token punctuation">)</span><span class="token punctuation">{</span><span class="token punctuation">}</span>
    <span class="token function">Test</span><span class="token punctuation">(</span><span class="token keyword">int</span> _n<span class="token punctuation">,</span> <span class="token keyword">int</span> _max<span class="token punctuation">)</span><span class="token operator">:</span>
        <span class="token function">n</span><span class="token punctuation">(</span>_n<span class="token punctuation">)</span><span class="token punctuation">,</span> <span class="token function">max</span><span class="token punctuation">(</span>_max<span class="token punctuation">)</span><span class="token punctuation">{</span><span class="token punctuation">}</span>
<span class="token keyword">private</span><span class="token operator">:</span>
    <span class="token keyword">int</span> n<span class="token punctuation">;</span>
    <span class="token keyword">const</span> <span class="token keyword">int</span> max<span class="token punctuation">;</span>
<span class="token punctuation">}</span><span class="token punctuation">;</span>
</code></pre>
<h3 id="basic-constructor">Basic Constructor</h3>
<ul>
<li>만약 생성자를 하나도 작성하지 않으면 컴파일러가 자동으로 기본생성자를 만들어, 객체 생성시에 호출한다.</li>
<li>생성자를 하나라도 선언한다면, 기본 생성자는 자동으로 생기지 않는다.</li>
</ul>
<pre class=" language-cpp"><code class="prism  language-cpp"><span class="token keyword">class</span> <span class="token class-name">Vector</span><span class="token punctuation">{</span>
<span class="token keyword">public</span><span class="token operator">:</span>
	<span class="token function">Vector</span><span class="token punctuation">(</span><span class="token keyword">int</span> _x<span class="token punctuation">,</span> <span class="token keyword">int</span> _y<span class="token punctuation">)</span><span class="token operator">:</span>
		<span class="token function">x</span><span class="token punctuation">(</span>_x<span class="token punctuation">)</span><span class="token punctuation">,</span>
		<span class="token function">y</span><span class="token punctuation">(</span>_y<span class="token punctuation">)</span><span class="token punctuation">{</span><span class="token punctuation">}</span>
<span class="token keyword">private</span><span class="token operator">:</span>
	<span class="token keyword">int</span> x<span class="token punctuation">;</span>
	<span class="token keyword">int</span> y<span class="token punctuation">;</span>
<span class="token punctuation">}</span><span class="token punctuation">;</span>

<span class="token keyword">int</span> <span class="token function">main</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">{</span>
	Vector <span class="token function">a</span><span class="token punctuation">(</span><span class="token number">1</span><span class="token punctuation">,</span> <span class="token number">2</span><span class="token punctuation">)</span><span class="token punctuation">;</span><span class="token comment">//okay</span>
	Vector b<span class="token punctuation">;</span><span class="token comment">//compile error: no matching function for call to `Vector::Vector()`</span>
	<span class="token keyword">return</span> <span class="token number">0</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre>
<ul>
<li>이때의 기본 생성자는 인자를 하나도 받지 않는 inline함수이다. <code>className(){}</code></li>
<li>만약 class내부에 기본 타입(ex int, double)이 아니라 다른 class가 존재한다면, 기본생성자에서 해당 class의 기본생성자를 자동으로 호출해준다.</li>
</ul>
<h1 id="destructor">Destructor</h1>
<p>new로 만든 객체를 delete하거나 더 이상 유효하지 않은 stack에 선언된 객체인 경우, 소멸자가 호출된다.<br>
소멸자는 class이름 앞에 ~를 붙인 형태를 선언한다.</p>
<pre class=" language-cpp"><code class="prism  language-cpp"><span class="token keyword">class</span> <span class="token class-name">MyString</span><span class="token punctuation">{</span>
<span class="token keyword">public</span><span class="token operator">:</span>
    <span class="token function">MyString</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token operator">:</span>
        <span class="token function">capacity</span><span class="token punctuation">(</span><span class="token number">16</span><span class="token punctuation">)</span><span class="token punctuation">,</span> <span class="token function">length</span><span class="token punctuation">(</span><span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">{</span>
        cout <span class="token operator">&lt;&lt;</span> <span class="token string">"created"</span> <span class="token operator">&lt;&lt;</span> endl<span class="token punctuation">;</span>
        string <span class="token operator">=</span> <span class="token keyword">new</span> <span class="token keyword">char</span><span class="token punctuation">[</span>capacity<span class="token punctuation">]</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
    <span class="token operator">~</span><span class="token function">MyString</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">{</span>
        cout <span class="token operator">&lt;&lt;</span> <span class="token string">"deleted"</span><span class="token operator">&lt;&lt;</span> endl<span class="token punctuation">;</span>
        <span class="token keyword">delete</span> string<span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
<span class="token keyword">private</span><span class="token operator">:</span>
    <span class="token keyword">char</span><span class="token operator">*</span> string<span class="token punctuation">;</span>
    <span class="token keyword">int</span> length<span class="token punctuation">;</span>
    <span class="token keyword">int</span> capacity<span class="token punctuation">;</span>

<span class="token punctuation">}</span><span class="token punctuation">;</span>
<span class="token keyword">int</span> <span class="token function">main</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">{</span>
    MyString<span class="token operator">*</span> str <span class="token operator">=</span> <span class="token keyword">new</span> <span class="token function">MyString</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
    <span class="token keyword">delete</span> str<span class="token punctuation">;</span>
	<span class="token keyword">return</span> <span class="token number">0</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre>
<h1 id="const-method">const method</h1>
<p>멤버함수 뒤에 const 를 붙이면 const method로 해당 함수에서는 member변수의 어느 값도 바꾸지 않는다는 뜻이다.<br>
만약 const method내부에서 멤버변수의 값을 수정하면 컴파일에러가 발생한다.<br>
기본적으로 모든 method는 const method로 선언하는 것이 안전하며, 멤버변수의 값을 수정할 필요가 있는 함수만 const를 제거하는 것이 바람직하다.</p>
<pre class=" language-cpp"><code class="prism  language-cpp"><span class="token keyword">class</span> <span class="token class-name">Vector</span><span class="token punctuation">{</span>
<span class="token keyword">public</span><span class="token operator">:</span>
	<span class="token function">Vector</span><span class="token punctuation">(</span><span class="token keyword">int</span> _x <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">,</span> <span class="token keyword">int</span> _y <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">)</span><span class="token operator">:</span>
		<span class="token function">x</span><span class="token punctuation">(</span>_x<span class="token punctuation">)</span><span class="token punctuation">,</span>
		<span class="token function">y</span><span class="token punctuation">(</span>_y<span class="token punctuation">)</span><span class="token punctuation">{</span><span class="token punctuation">}</span>
	<span class="token keyword">int</span> <span class="token function">getX</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">const</span><span class="token punctuation">{</span>
        <span class="token keyword">return</span> x<span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
	<span class="token keyword">int</span> <span class="token function">getY</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token keyword">const</span><span class="token punctuation">{</span>
        <span class="token keyword">return</span> y<span class="token punctuation">;</span>
	<span class="token punctuation">}</span>
<span class="token keyword">private</span><span class="token operator">:</span>
	<span class="token keyword">int</span> x<span class="token punctuation">;</span>
	<span class="token keyword">int</span> y<span class="token punctuation">;</span>
<span class="token punctuation">}</span><span class="token punctuation">;</span>
</code></pre>
<h1 id="struct-vs-class">Struct vs Class</h1>
<p>CPP에서는 struct도 method와 생성자, 소멸자, access modifier등을 가질 수 있다.<br>
차이점은 struct에서는 access modifier를 따로 표시해주지 않으면 public으로 선언되지만,  class는 private으로 선언되는 것 말고는 없다.</p>
<p>+) 일반적으로 struct를 사용한다면 method를 사용하는 것을 지양한다.</p>
<pre class=" language-cpp"><code class="prism  language-cpp"><span class="token keyword">struct</span> Circle<span class="token punctuation">{</span>
    <span class="token keyword">int</span> x<span class="token punctuation">;</span>
    <span class="token keyword">int</span> y<span class="token punctuation">;</span>
    <span class="token keyword">int</span> radius <span class="token punctuation">;</span>
    <span class="token function">Circle</span><span class="token punctuation">(</span><span class="token keyword">int</span> _x<span class="token punctuation">,</span> <span class="token keyword">int</span> _y<span class="token punctuation">,</span> <span class="token keyword">int</span> _r<span class="token punctuation">)</span><span class="token operator">:</span>
        <span class="token function">x</span><span class="token punctuation">(</span>_x<span class="token punctuation">)</span><span class="token punctuation">,</span> <span class="token function">y</span><span class="token punctuation">(</span>_y<span class="token punctuation">)</span><span class="token punctuation">,</span> <span class="token function">radius</span><span class="token punctuation">(</span>_r<span class="token punctuation">)</span><span class="token punctuation">{</span><span class="token punctuation">}</span>
    <span class="token function">Circle</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token operator">:</span>
        <span class="token function">x</span><span class="token punctuation">(</span><span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">,</span> <span class="token function">y</span><span class="token punctuation">(</span><span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">,</span> <span class="token function">radius</span><span class="token punctuation">(</span><span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">{</span><span class="token punctuation">}</span>
<span class="token punctuation">}</span><span class="token punctuation">;</span>
</code></pre>

