<h1>cnav - Command Navigator</h1>
<p><strong>cnav</strong> is a lightweight CLI tool designed to simplify your workflow by aliasing long, complex, and frequently used commands. With <code>cnav</code>, you can easily create, manage, and use command shortcuts, saving you time and effort.</p>

<h2>Features</h2>
<ul>
    <li><strong>Create Aliases:</strong> Replace lengthy commands with simple shortcuts.</li>
    <li><strong>View Aliases:</strong> Quickly see all your current shortcuts.</li>
    <li><strong>Manage Aliases:</strong> Remove or clear all aliases as needed.</li>
    <li><strong>Easy-to-Use Syntax:</strong> Simple commands for everyday convenience.</li>
</ul>

<h2>Usage</h2>
<h3>Add a Command Alias</h3>
<pre><code>cnav -add &lt;alias&gt; &lt;command&gt;</code></pre>
<p>Example:</p>
<pre><code>cnav -add ll "ls -la"</code></pre>

<h3>Use a Command Alias</h3>
<pre><code>cnav &lt;alias&gt;</code></pre>
<p>Example:</p>
<pre><code>cnav ll</code></pre>

<h3>List All Aliases</h3>
<pre><code>cnav -print</code></pre>

<h3>Remove an Alias</h3>
<pre><code>cnav -rem &lt;alias&gt;</code></pre>
<p>Example:</p>
<pre><code>cnav -rem ll</code></pre>

<h3>Clear All Aliases</h3>
<pre><code>cnav -clear</code></pre>

<h2>Why Choose cnav?</h2>
<p>Do you find yourself repeatedly typing out long, tedious commands? <strong>cnav</strong> is here to streamline your command-line experience. It’s lightweight, efficient, and simple to use, helping you focus on what really matters.</p>
