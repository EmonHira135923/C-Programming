<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>C Programming — Master Reference</title>
<link href="https://fonts.googleapis.com/css2?family=JetBrains+Mono:wght@300;400;500;600;700&family=Syne:wght@400;600;700;800&family=IBM+Plex+Sans:wght@300;400;500;600&display=swap" rel="stylesheet">
<style>
  :root {
    --bg: #0a0c10;
    --bg2: #0f1117;
    --bg3: #151820;
    --panel: #1a1d27;
    --border: #252836;
    --accent: #00d4ff;
    --accent2: #7c3aed;
    --accent3: #f59e0b;
    --accent4: #10b981;
    --accent5: #f43f5e;
    --text: #e2e8f0;
    --text2: #94a3b8;
    --text3: #64748b;
    --code-bg: #111420;
    --code-border: #1e2235;
  }

  * { margin: 0; padding: 0; box-sizing: border-box; }

  html { scroll-behavior: smooth; }

  body {
    background: var(--bg);
    color: var(--text);
    font-family: 'IBM Plex Sans', sans-serif;
    font-size: 15px;
    line-height: 1.7;
    overflow-x: hidden;
  }

  /* NOISE TEXTURE */
  body::before {
    content: '';
    position: fixed;
    inset: 0;
    background-image: url("data:image/svg+xml,%3Csvg viewBox='0 0 256 256' xmlns='http://www.w3.org/2000/svg'%3E%3Cfilter id='noise'%3E%3CfeTurbulence type='fractalNoise' baseFrequency='0.9' numOctaves='4' stitchTiles='stitch'/%3E%3C/filter%3E%3Crect width='100%25' height='100%25' filter='url(%23noise)' opacity='0.04'/%3E%3C/svg%3E");
    pointer-events: none;
    z-index: 0;
  }

  /* HERO */
  .hero {
    position: relative;
    min-height: 100vh;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
    text-align: center;
    padding: 4rem 2rem;
    overflow: hidden;
  }

  .hero-grid {
    position: absolute;
    inset: 0;
    background-image:
      linear-gradient(rgba(0,212,255,0.04) 1px, transparent 1px),
      linear-gradient(90deg, rgba(0,212,255,0.04) 1px, transparent 1px);
    background-size: 60px 60px;
    animation: gridPan 20s linear infinite;
  }

  @keyframes gridPan {
    0% { transform: translateY(0); }
    100% { transform: translateY(60px); }
  }

  .hero-glow {
    position: absolute;
    width: 600px;
    height: 600px;
    border-radius: 50%;
    background: radial-gradient(circle, rgba(0,212,255,0.08) 0%, transparent 70%);
    top: 50%;
    left: 50%;
    transform: translate(-50%, -50%);
    animation: pulse 4s ease-in-out infinite;
  }

  .hero-glow2 {
    position: absolute;
    width: 400px;
    height: 400px;
    border-radius: 50%;
    background: radial-gradient(circle, rgba(124,58,237,0.08) 0%, transparent 70%);
    top: 30%;
    right: 15%;
    animation: pulse 5s ease-in-out infinite reverse;
  }

  @keyframes pulse {
    0%, 100% { opacity: 0.6; transform: translate(-50%, -50%) scale(1); }
    50% { opacity: 1; transform: translate(-50%, -50%) scale(1.1); }
  }

  .hero-badge {
    position: relative;
    display: inline-flex;
    align-items: center;
    gap: 8px;
    background: rgba(0,212,255,0.08);
    border: 1px solid rgba(0,212,255,0.2);
    border-radius: 100px;
    padding: 6px 18px;
    font-family: 'JetBrains Mono', monospace;
    font-size: 12px;
    color: var(--accent);
    letter-spacing: 0.1em;
    text-transform: uppercase;
    margin-bottom: 2rem;
    animation: fadeDown 0.6s ease both;
  }

  .hero-badge::before {
    content: '';
    width: 6px;
    height: 6px;
    border-radius: 50%;
    background: var(--accent);
    animation: blink 1.5s ease-in-out infinite;
  }

  @keyframes blink {
    0%, 100% { opacity: 1; }
    50% { opacity: 0.2; }
  }

  .hero h1 {
    position: relative;
    font-family: 'Syne', sans-serif;
    font-size: clamp(3rem, 8vw, 7rem);
    font-weight: 800;
    line-height: 0.9;
    letter-spacing: -0.03em;
    margin-bottom: 1.5rem;
    animation: fadeDown 0.6s ease 0.1s both;
  }

  .hero h1 .c-letter {
    display: inline-block;
    background: linear-gradient(135deg, var(--accent), var(--accent2));
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
    background-clip: text;
  }

  .hero-subtitle {
    position: relative;
    font-size: 1.1rem;
    color: var(--text2);
    max-width: 560px;
    margin-bottom: 3rem;
    animation: fadeDown 0.6s ease 0.2s both;
  }

  .hero-stats {
    position: relative;
    display: flex;
    gap: 2px;
    flex-wrap: wrap;
    justify-content: center;
    animation: fadeDown 0.6s ease 0.3s both;
  }

  .stat-chip {
    background: var(--panel);
    border: 1px solid var(--border);
    border-radius: 8px;
    padding: 10px 20px;
    text-align: center;
  }

  .stat-chip .num {
    font-family: 'Syne', sans-serif;
    font-size: 1.6rem;
    font-weight: 800;
    color: var(--accent);
    line-height: 1;
  }

  .stat-chip .label {
    font-size: 11px;
    color: var(--text3);
    text-transform: uppercase;
    letter-spacing: 0.08em;
    margin-top: 2px;
  }

  .scroll-indicator {
    position: absolute;
    bottom: 2rem;
    left: 50%;
    transform: translateX(-50%);
    display: flex;
    flex-direction: column;
    align-items: center;
    gap: 8px;
    color: var(--text3);
    font-size: 11px;
    letter-spacing: 0.1em;
    text-transform: uppercase;
    animation: fadeDown 0.6s ease 0.5s both;
  }

  .scroll-line {
    width: 1px;
    height: 40px;
    background: linear-gradient(to bottom, var(--accent), transparent);
    animation: scrollAnim 2s ease-in-out infinite;
  }

  @keyframes scrollAnim {
    0%, 100% { opacity: 0.3; transform: scaleY(1); }
    50% { opacity: 1; transform: scaleY(1.2); }
  }

  @keyframes fadeDown {
    from { opacity: 0; transform: translateY(-20px); }
    to { opacity: 1; transform: translateY(0); }
  }

  /* NAV */
  .toc-nav {
    position: sticky;
    top: 0;
    z-index: 100;
    background: rgba(10,12,16,0.9);
    backdrop-filter: blur(20px);
    border-bottom: 1px solid var(--border);
    padding: 0 2rem;
    overflow-x: auto;
    scrollbar-width: none;
  }

  .toc-nav::-webkit-scrollbar { display: none; }

  .toc-inner {
    display: flex;
    gap: 0;
    max-width: 1200px;
    margin: 0 auto;
    min-width: max-content;
  }

  .toc-link {
    display: flex;
    align-items: center;
    gap: 6px;
    padding: 14px 16px;
    color: var(--text3);
    text-decoration: none;
    font-size: 12px;
    font-weight: 500;
    letter-spacing: 0.05em;
    text-transform: uppercase;
    white-space: nowrap;
    border-bottom: 2px solid transparent;
    transition: all 0.2s;
  }

  .toc-link:hover {
    color: var(--accent);
    border-bottom-color: var(--accent);
  }

  .toc-link .num {
    font-family: 'JetBrains Mono', monospace;
    font-size: 10px;
    color: var(--text3);
    opacity: 0.5;
  }

  /* MAIN LAYOUT */
  .main {
    max-width: 1000px;
    margin: 0 auto;
    padding: 0 2rem 6rem;
  }

  /* SECTIONS */
  .section {
    margin-top: 6rem;
  }

  .section-header {
    display: flex;
    align-items: center;
    gap: 1rem;
    margin-bottom: 2.5rem;
    padding-bottom: 1rem;
    border-bottom: 1px solid var(--border);
  }

  .section-num {
    font-family: 'JetBrains Mono', monospace;
    font-size: 11px;
    color: var(--accent);
    background: rgba(0,212,255,0.08);
    border: 1px solid rgba(0,212,255,0.15);
    border-radius: 6px;
    padding: 4px 10px;
    letter-spacing: 0.1em;
    flex-shrink: 0;
  }

  .section-title {
    font-family: 'Syne', sans-serif;
    font-size: 1.8rem;
    font-weight: 700;
    color: var(--text);
  }

  .section-file {
    margin-left: auto;
    font-family: 'JetBrains Mono', monospace;
    font-size: 12px;
    color: var(--text3);
    background: var(--panel);
    border: 1px solid var(--border);
    border-radius: 6px;
    padding: 4px 12px;
    flex-shrink: 0;
  }

  /* DEFINITION BLOCK */
  .definition {
    background: linear-gradient(135deg, rgba(0,212,255,0.04), rgba(124,58,237,0.04));
    border: 1px solid rgba(0,212,255,0.12);
    border-left: 3px solid var(--accent);
    border-radius: 0 12px 12px 0;
    padding: 1.2rem 1.5rem;
    margin-bottom: 2rem;
    font-size: 14px;
    color: var(--text2);
    line-height: 1.8;
  }

  .definition strong {
    color: var(--accent);
    font-weight: 600;
  }

  /* CODE BLOCKS */
  .code-block {
    background: var(--code-bg);
    border: 1px solid var(--code-border);
    border-radius: 12px;
    overflow: hidden;
    margin-bottom: 2rem;
    font-family: 'JetBrains Mono', monospace;
  }

  .code-header {
    display: flex;
    align-items: center;
    justify-content: space-between;
    padding: 12px 16px;
    background: rgba(255,255,255,0.02);
    border-bottom: 1px solid var(--code-border);
  }

  .code-dots {
    display: flex;
    gap: 6px;
  }

  .code-dots span {
    width: 10px;
    height: 10px;
    border-radius: 50%;
  }

  .dot-red { background: #ff5f57; }
  .dot-yellow { background: #ffbd2e; }
  .dot-green { background: #28ca41; }

  .code-filename {
    font-size: 12px;
    color: var(--text3);
  }

  .code-lang {
    font-size: 11px;
    color: var(--accent);
    letter-spacing: 0.08em;
    text-transform: uppercase;
  }

  pre {
    padding: 1.5rem;
    overflow-x: auto;
    font-size: 13.5px;
    line-height: 1.7;
  }

  /* Syntax highlighting */
  .kw { color: #c792ea; }
  .fn { color: #82aaff; }
  .str { color: #c3e88d; }
  .cm { color: #546e7a; font-style: italic; }
  .num2 { color: #f78c6c; }
  .inc { color: #ffcb6b; }
  .fmt { color: #00d4ff; }
  .op { color: #89ddff; }
  .var { color: #e2e8f0; }
  .punc { color: #89ddff; }

  /* TABLES */
  .table-wrap {
    overflow-x: auto;
    margin-bottom: 2rem;
    border-radius: 12px;
    border: 1px solid var(--border);
  }

  table {
    width: 100%;
    border-collapse: collapse;
    font-size: 14px;
  }

  thead tr {
    background: var(--panel);
  }

  thead th {
    padding: 12px 16px;
    text-align: left;
    font-family: 'JetBrains Mono', monospace;
    font-size: 11px;
    font-weight: 600;
    color: var(--text3);
    text-transform: uppercase;
    letter-spacing: 0.08em;
    white-space: nowrap;
  }

  tbody tr {
    border-top: 1px solid var(--border);
    transition: background 0.15s;
  }

  tbody tr:hover {
    background: rgba(255,255,255,0.02);
  }

  tbody td {
    padding: 11px 16px;
    color: var(--text2);
    vertical-align: top;
  }

  tbody td:first-child {
    color: var(--text);
    font-weight: 500;
  }

  code {
    font-family: 'JetBrains Mono', monospace;
    font-size: 0.88em;
    background: rgba(0,212,255,0.07);
    color: var(--accent);
    border: 1px solid rgba(0,212,255,0.15);
    border-radius: 5px;
    padding: 2px 7px;
  }

  /* SUBSECTION */
  .subsection {
    margin-top: 2.5rem;
    margin-bottom: 1.5rem;
  }

  .subsection h3 {
    font-family: 'Syne', sans-serif;
    font-size: 1.1rem;
    font-weight: 700;
    color: var(--text);
    margin-bottom: 1rem;
    display: flex;
    align-items: center;
    gap: 10px;
  }

  .subsection h3::before {
    content: '';
    width: 3px;
    height: 18px;
    background: var(--accent2);
    border-radius: 2px;
  }

  /* ALERT / TIP */
  .tip {
    display: flex;
    gap: 12px;
    background: rgba(245,158,11,0.06);
    border: 1px solid rgba(245,158,11,0.2);
    border-radius: 10px;
    padding: 14px 16px;
    margin-bottom: 1.5rem;
    font-size: 13.5px;
    color: var(--text2);
  }

  .tip .tip-icon {
    font-size: 16px;
    flex-shrink: 0;
    margin-top: 1px;
  }

  .warning {
    background: rgba(244,63,94,0.06);
    border-color: rgba(244,63,94,0.2);
  }

  .info {
    background: rgba(0,212,255,0.04);
    border-color: rgba(0,212,255,0.15);
  }

  /* OPERATOR CATEGORIES */
  .op-grid {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(280px, 1fr));
    gap: 1rem;
    margin-bottom: 2rem;
  }

  .op-card {
    background: var(--panel);
    border: 1px solid var(--border);
    border-radius: 12px;
    overflow: hidden;
  }

  .op-card-header {
    padding: 10px 16px;
    font-family: 'JetBrains Mono', monospace;
    font-size: 11px;
    font-weight: 600;
    letter-spacing: 0.08em;
    text-transform: uppercase;
  }

  .op-card-header.arith { background: rgba(0,212,255,0.08); color: var(--accent); }
  .op-card-header.relat { background: rgba(16,185,129,0.08); color: var(--accent4); }
  .op-card-header.logic { background: rgba(124,58,237,0.08); color: #a78bfa; }
  .op-card-header.bitw { background: rgba(245,158,11,0.08); color: var(--accent3); }
  .op-card-header.assign { background: rgba(244,63,94,0.08); color: var(--accent5); }

  .op-card table { font-size: 13px; }
  .op-card thead th { font-size: 10px; }

  /* LOOP COMPARISON */
  .loop-compare {
    display: grid;
    grid-template-columns: repeat(3, 1fr);
    gap: 1rem;
    margin-bottom: 2rem;
  }

  .loop-card {
    background: var(--panel);
    border: 1px solid var(--border);
    border-radius: 12px;
    padding: 1.2rem;
  }

  .loop-card h4 {
    font-family: 'JetBrains Mono', monospace;
    font-size: 14px;
    font-weight: 700;
    margin-bottom: 1rem;
    padding-bottom: 8px;
    border-bottom: 1px solid var(--border);
  }

  .loop-card h4.for-c { color: var(--accent); }
  .loop-card h4.while-c { color: var(--accent4); }
  .loop-card h4.dowhile-c { color: var(--accent3); }

  .loop-feature {
    display: flex;
    justify-content: space-between;
    padding: 5px 0;
    font-size: 13px;
    border-bottom: 1px solid rgba(255,255,255,0.03);
  }

  .loop-feature .lk { color: var(--text3); font-size: 12px; }
  .loop-feature .lv { color: var(--text); font-family: 'JetBrains Mono', monospace; font-size: 12px; }

  /* CHECKLIST */
  .checklist-grid {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(280px, 1fr));
    gap: 0.5rem;
  }

  .check-item {
    display: flex;
    align-items: center;
    gap: 10px;
    padding: 10px 14px;
    background: var(--panel);
    border: 1px solid var(--border);
    border-radius: 8px;
    font-size: 13.5px;
    color: var(--text2);
    transition: all 0.2s;
  }

  .check-item:hover { border-color: rgba(0,212,255,0.3); }

  .check-icon {
    width: 20px;
    height: 20px;
    border-radius: 50%;
    background: rgba(16,185,129,0.15);
    border: 1.5px solid rgba(16,185,129,0.4);
    display: flex;
    align-items: center;
    justify-content: center;
    font-size: 10px;
    color: var(--accent4);
    flex-shrink: 0;
  }

  /* NEXT STEPS */
  .next-grid {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
    gap: 1rem;
  }

  .next-card {
    background: var(--panel);
    border: 1px solid var(--border);
    border-radius: 12px;
    padding: 1.2rem;
    transition: all 0.2s;
  }

  .next-card:hover {
    border-color: rgba(0,212,255,0.3);
    transform: translateY(-2px);
  }

  .next-card .icon { font-size: 1.5rem; margin-bottom: 8px; }
  .next-card h4 { font-family: 'Syne', sans-serif; font-size: 14px; font-weight: 700; margin-bottom: 4px; }
  .next-card p { font-size: 12px; color: var(--text3); }

  /* PRO TIPS */
  .tips-list {
    display: flex;
    flex-direction: column;
    gap: 0.6rem;
  }

  .pro-tip {
    display: flex;
    gap: 14px;
    align-items: flex-start;
    padding: 14px 16px;
    background: var(--panel);
    border: 1px solid var(--border);
    border-radius: 10px;
    font-size: 14px;
    transition: all 0.2s;
  }

  .pro-tip:hover { border-color: rgba(0,212,255,0.25); }

  .pro-tip .tip-num {
    font-family: 'JetBrains Mono', monospace;
    font-size: 11px;
    color: var(--accent);
    background: rgba(0,212,255,0.08);
    border: 1px solid rgba(0,212,255,0.15);
    border-radius: 5px;
    padding: 2px 8px;
    flex-shrink: 0;
    margin-top: 2px;
  }

  .pro-tip strong { color: var(--text); }
  .pro-tip span { color: var(--text2); }

  /* FOOTER */
  .footer {
    text-align: center;
    padding: 4rem 2rem;
    border-top: 1px solid var(--border);
    margin-top: 6rem;
  }

  .footer-logo {
    font-family: 'Syne', sans-serif;
    font-size: 2.5rem;
    font-weight: 800;
    background: linear-gradient(135deg, var(--accent), var(--accent2));
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
    background-clip: text;
    margin-bottom: 1rem;
  }

  .footer p { color: var(--text3); font-size: 13px; }

  /* DIVIDER */
  .divider {
    height: 1px;
    background: linear-gradient(to right, transparent, var(--border), transparent);
    margin: 3rem 0;
  }

  /* Precedence table special */
  .prec-table td:nth-child(1) { font-family: 'JetBrains Mono', monospace; font-size: 12px; font-weight: 700; color: var(--accent); }
  .prec-table td:nth-child(2) { font-family: 'JetBrains Mono', monospace; font-size: 12px; color: var(--text2); }

  @media (max-width: 600px) {
    .loop-compare { grid-template-columns: 1fr; }
    .section-file { display: none; }
    .hero h1 { font-size: 3rem; }
  }
</style>
</head>
<body>

<!-- HERO -->
<section class="hero">
  <div class="hero-grid"></div>
  <div class="hero-glow"></div>
  <div class="hero-glow2"></div>

  <div class="hero-badge">Complete Reference Guide · 2026</div>

  <h1>
    <span class="c-letter">C</span> Programming<br>Fundamentals
  </h1>

  <p class="hero-subtitle">
    From Hello World to Loops — a complete theory-first guide covering all core concepts with examples, tables, and deep explanations.
  </p>

  <div class="hero-stats">
    <div class="stat-chip"><div class="num">10</div><div class="label">Topics</div></div>
    <div class="stat-chip"><div class="num">24</div><div class="label">Concepts</div></div>
    <div class="stat-chip"><div class="num">9</div><div class="label">Operator Types</div></div>
    <div class="stat-chip"><div class="num">3</div><div class="label">Loop Structures</div></div>
    <div class="stat-chip"><div class="num">6</div><div class="label">Conditionals</div></div>
  </div>

  <div class="scroll-indicator">
    <div class="scroll-line"></div>
    scroll
  </div>
</section>

<!-- NAV -->
<nav class="toc-nav">
  <div class="toc-inner">
    <a href="#hello" class="toc-link"><span class="num">01</span> Hello World</a>
    <a href="#escape" class="toc-link"><span class="num">02</span> Escape Sequences</a>
    <a href="#variables" class="toc-link"><span class="num">03</span> Variables</a>
    <a href="#datatypes" class="toc-link"><span class="num">04</span> Data Types</a>
    <a href="#input" class="toc-link"><span class="num">05</span> User Input</a>
    <a href="#naming" class="toc-link"><span class="num">06</span> Naming Rules</a>
    <a href="#limits" class="toc-link"><span class="num">07</span> Limitations</a>
    <a href="#operators" class="toc-link"><span class="num">08</span> Operators</a>
    <a href="#conditions" class="toc-link"><span class="num">09</span> Conditions</a>
    <a href="#loops" class="toc-link"><span class="num">10</span> Loops</a>
  </div>
</nav>

<!-- MAIN -->
<main class="main">

  <!-- ═══════════════ SECTION 1 ═══════════════ -->
  <section class="section" id="hello">
    <div class="section-header">
      <span class="section-num">01</span>
      <h2 class="section-title">Hello World Program</h2>
      <span class="section-file">hello.c</span>
    </div>

    <div class="definition">
      <strong>Program Structure:</strong> প্রতিটি C প্রোগ্রামের একটি নির্দিষ্ট কাঠামো আছে — Header File, Main Function, এবং Statements। এই কাঠামো না মানলে প্রোগ্রাম compile হবে না।
    </div>

    <div class="code-block">
      <div class="code-header">
        <div class="code-dots"><span class="dot-red"></span><span class="dot-yellow"></span><span class="dot-green"></span></div>
        <span class="code-filename">hello.c</span>
        <span class="code-lang">C</span>
      </div>
      <pre><span class="inc">#include</span> <span class="str">&lt;stdio.h&gt;</span>

<span class="kw">int</span> <span class="fn">main</span><span class="punc">() {</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Hello World"</span><span class="punc">);</span>
    <span class="kw">return</span> <span class="num2">0</span><span class="punc">;</span>
<span class="punc">}</span></pre>
    </div>

    <div class="subsection"><h3>প্রতিটি Component এর ব্যাখ্যা</h3></div>
    <div class="table-wrap">
      <table>
        <thead><tr><th>Component</th><th>নাম</th><th>কাজ কী করে</th></tr></thead>
        <tbody>
          <tr><td><code>#include &lt;stdio.h&gt;</code></td><td>Header File</td><td>Standard Input/Output library লোড করে — <code>printf()</code> ও <code>scanf()</code> ব্যবহার করতে এটা লাগে</td></tr>
          <tr><td><code>int main()</code></td><td>Main Function</td><td>প্রোগ্রামের শুরুর বিন্দু — execution এখান থেকে শুরু হয়</td></tr>
          <tr><td><code>{ }</code></td><td>Curly Braces</td><td>Function এর body define করে — এর ভেতরে সব code লেখা হয়</td></tr>
          <tr><td><code>printf()</code></td><td>Output Function</td><td>Screen-এ formatted text print করে</td></tr>
          <tr><td><code>return 0;</code></td><td>Return Statement</td><td>প্রোগ্রাম সফলভাবে শেষ হয়েছে OS কে জানায়। 0 = সফল</td></tr>
          <tr><td><code>;</code></td><td>Semicolon</td><td>Statement শেষের চিহ্ন — প্রতিটি statement এ দিতে হয়</td></tr>
        </tbody>
      </table>
    </div>

    <div class="subsection"><h3>Compile ও Run করার উপায়</h3></div>
    <div class="code-block">
      <div class="code-header">
        <div class="code-dots"><span class="dot-red"></span><span class="dot-yellow"></span><span class="dot-green"></span></div>
        <span class="code-filename">Terminal</span>
        <span class="code-lang">bash</span>
      </div>
      <pre><span class="cm"># Compile করুন</span>
gcc hello.c -o hello

<span class="cm"># Run করুন (Linux/macOS)</span>
./hello

<span class="cm"># Run করুন (Windows)</span>
hello.exe</pre>
    </div>
  </section>

  <!-- ═══════════════ SECTION 2 ═══════════════ -->
  <section class="section" id="escape">
    <div class="section-header">
      <span class="section-num">02</span>
      <h2 class="section-title">Escape Sequences</h2>
      <span class="section-file">specialCharacter.c</span>
    </div>

    <div class="definition">
      <strong>Escape Sequence কী:</strong> Escape sequences হলো বিশেষ character combination যা backslash (<code>\</code>) দিয়ে শুরু হয়। এগুলো non-printable বা special character represent করে — যেমন নতুন লাইনে যাওয়া, tab দেওয়া ইত্যাদি।
    </div>

    <div class="code-block">
      <div class="code-header">
        <div class="code-dots"><span class="dot-red"></span><span class="dot-yellow"></span><span class="dot-green"></span></div>
        <span class="code-filename">specialCharacter.c</span>
        <span class="code-lang">C</span>
      </div>
      <pre><span class="inc">#include</span><span class="str">&lt;stdio.h&gt;</span>

<span class="kw">int</span> <span class="fn">main</span><span class="punc">(){</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"New Line:\n Hello\nWorld\n\n"</span><span class="punc">);</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Tab:\t Hello\t World\n\n"</span><span class="punc">);</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Backslash: \\\n"</span><span class="punc">);</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Double Quote: \"Hello\"\n"</span><span class="punc">);</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Percentage: 100%%\n"</span><span class="punc">);</span>
    <span class="kw">return</span> <span class="num2">0</span><span class="punc">;</span>
<span class="punc">}</span></pre>
    </div>

    <div class="table-wrap">
      <table>
        <thead><tr><th>Escape Sequence</th><th>অর্থ</th><th>Effect</th><th>কখন ব্যবহার করবে</th></tr></thead>
        <tbody>
          <tr><td><code>\n</code></td><td>New Line</td><td>পরের লাইনে যায়</td><td>Output কে multiple line-এ ভাগ করতে</td></tr>
          <tr><td><code>\t</code></td><td>Horizontal Tab</td><td>Tab space insert হয় (4–8 space)</td><td>Column align করতে, table বানাতে</td></tr>
          <tr><td><code>\\</code></td><td>Backslash</td><td>একটি <code>\</code> print হয়</td><td>File path দেখাতে: <code>C:\\Users</code></td></tr>
          <tr><td><code>\"</code></td><td>Double Quote</td><td><code>"</code> print হয়</td><td>String এর মধ্যে quote দেখাতে</td></tr>
          <tr><td><code>\'</code></td><td>Single Quote</td><td><code>'</code> print হয়</td><td>Character এর মধ্যে apostrophe দেখাতে</td></tr>
          <tr><td><code>\a</code></td><td>Alert / Bell</td><td>Beep sound হয়</td><td>Warning বা notification এ</td></tr>
          <tr><td><code>\b</code></td><td>Backspace</td><td>আগের character মুছে</td><td>Text manipulation এ</td></tr>
          <tr><td><code>\r</code></td><td>Carriage Return</td><td>Line এর শুরুতে ফেরে</td><td>Progress bar এ</td></tr>
          <tr><td><code>\0</code></td><td>Null Character</td><td>String এর শেষ চিহ্ন</td><td>String terminate করতে</td></tr>
          <tr><td><code>%%</code></td><td>Percent Sign</td><td>একটি <code>%</code> print হয়</td><td>Percentage দেখাতে: <code>100%%</code></td></tr>
        </tbody>
      </table>
    </div>

    <div class="tip info"><div class="tip-icon">💡</div><div><strong>মনে রাখো:</strong> <code>%</code> কে escape করতে <code>%%</code> লিখতে হয় — কারণ <code>%d</code>, <code>%f</code> এগুলো format specifier হিসেবে কাজ করে। <code>\</code> কে escape করতে <code>\\</code> লিখতে হয়।</div></div>
  </section>

  <!-- ═══════════════ SECTION 3 ═══════════════ -->
  <section class="section" id="variables">
    <div class="section-header">
      <span class="section-num">03</span>
      <h2 class="section-title">Variables</h2>
      <span class="section-file">hello_variable.c</span>
    </div>

    <div class="definition">
      <strong>Variable কী:</strong> Variable হলো memory-তে একটি named storage location যেখানে data রাখা যায় এবং পরিবর্তন করা যায়। প্রতিটি variable-এর একটি নাম (identifier), একটি data type, এবং একটি value থাকে।
    </div>

    <div class="code-block">
      <div class="code-header">
        <div class="code-dots"><span class="dot-red"></span><span class="dot-yellow"></span><span class="dot-green"></span></div>
        <span class="code-filename">hello_variable.c</span>
        <span class="code-lang">C</span>
      </div>
      <pre><span class="inc">#include</span><span class="str">&lt;stdio.h&gt;</span>

<span class="kw">int</span> <span class="fn">main</span><span class="punc">(){</span>
    <span class="kw">int</span>    a <span class="op">=</span> <span class="num2">10</span><span class="punc">;</span>        <span class="cm">// Integer variable</span>
    <span class="kw">char</span>   b <span class="op">=</span> <span class="str">'A'</span><span class="punc">;</span>      <span class="cm">// Character variable</span>
    <span class="kw">float</span>  c <span class="op">=</span> <span class="num2">5.5</span><span class="punc">;</span>      <span class="cm">// Float variable</span>
    <span class="kw">double</span> d <span class="op">=</span> <span class="num2">10.12345</span><span class="punc">;</span> <span class="cm">// Double variable</span>

    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Integer: <span class="fmt">%d</span>\n"</span>, a<span class="punc">);</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Character: <span class="fmt">%c</span>\n"</span>, b<span class="punc">);</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Float: <span class="fmt">%f</span>\n"</span>, c<span class="punc">);</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Double: <span class="fmt">%lf</span>\n"</span>, d<span class="punc">);</span>

    <span class="kw">return</span> <span class="num2">0</span><span class="punc">;</span>
<span class="punc">}</span></pre>
    </div>

    <div class="subsection"><h3>Variable এর তিনটি অপারেশন</h3></div>
    <div class="table-wrap">
      <table>
        <thead><tr><th>অপারেশন</th><th>Syntax</th><th>উদাহরণ</th><th>ব্যাখ্যা</th></tr></thead>
        <tbody>
          <tr><td>Declaration</td><td><code>data_type name;</code></td><td><code>int age;</code></td><td>Variable তৈরি হয়, কিন্তু কোনো value নেই (garbage value থাকে)</td></tr>
          <tr><td>Initialization</td><td><code>data_type name = value;</code></td><td><code>int age = 25;</code></td><td>Variable তৈরি এবং সাথে সাথে value দেওয়া</td></tr>
          <tr><td>Assignment</td><td><code>name = value;</code></td><td><code>age = 30;</code></td><td>আগে declare করা variable-এ নতুন value দেওয়া</td></tr>
        </tbody>
      </table>
    </div>

    <div class="subsection"><h3>Format Specifiers — সম্পূর্ণ তালিকা</h3></div>
    <div class="table-wrap">
      <table>
        <thead><tr><th>Data Type</th><th>Format Specifier</th><th>printf উদাহরণ</th><th>scanf উদাহরণ</th></tr></thead>
        <tbody>
          <tr><td><code>int</code></td><td><code>%d</code> বা <code>%i</code></td><td><code>printf("%d", age);</code></td><td><code>scanf("%d", &age);</code></td></tr>
          <tr><td><code>float</code></td><td><code>%f</code></td><td><code>printf("%f", price);</code></td><td><code>scanf("%f", &price);</code></td></tr>
          <tr><td><code>double</code></td><td><code>%lf</code></td><td><code>printf("%lf", pi);</code></td><td><code>scanf("%lf", &pi);</code></td></tr>
          <tr><td><code>char</code></td><td><code>%c</code></td><td><code>printf("%c", grade);</code></td><td><code>scanf(" %c", &grade);</code></td></tr>
          <tr><td>String</td><td><code>%s</code></td><td><code>printf("%s", name);</code></td><td><code>scanf("%s", name);</code></td></tr>
          <tr><td><code>unsigned int</code></td><td><code>%u</code></td><td><code>printf("%u", count);</code></td><td>—</td></tr>
          <tr><td>Hexadecimal</td><td><code>%x</code> / <code>%X</code></td><td><code>printf("%x", num);</code></td><td>—</td></tr>
          <tr><td>Octal</td><td><code>%o</code></td><td><code>printf("%o", num);</code></td><td>—</td></tr>
        </tbody>
      </table>
    </div>
  </section>

  <!-- ═══════════════ SECTION 4 ═══════════════ -->
  <section class="section" id="datatypes">
    <div class="section-header">
      <span class="section-num">04</span>
      <h2 class="section-title">Data Types</h2>
      <span class="section-file">helloDataTypes.c</span>
    </div>

    <div class="definition">
      <strong>Data Type কী:</strong> Data type নির্ধারণ করে একটি variable কী ধরনের data রাখতে পারবে, কতটুকু memory নেবে, এবং তার উপর কী ধরনের operation করা যাবে। সঠিক data type বাছাই না করলে data নষ্ট হয় বা memory waste হয়।
    </div>

    <div class="subsection"><h3>Primary Data Types</h3></div>
    <div class="table-wrap">
      <table>
        <thead><tr><th>Type</th><th>Size</th><th>Format</th><th>Range</th><th>কখন ব্যবহার করবে</th></tr></thead>
        <tbody>
          <tr><td><code>int</code></td><td>4 bytes</td><td><code>%d</code></td><td>-2,147,483,648 থেকে 2,147,483,647</td><td>গণনা, index, পূর্ণ সংখ্যা</td></tr>
          <tr><td><code>float</code></td><td>4 bytes</td><td><code>%f</code></td><td>±1.2e-38 থেকে ±3.4e38</td><td>দশমিক সংখ্যা (~7 digit precision)</td></tr>
          <tr><td><code>double</code></td><td>8 bytes</td><td><code>%lf</code></td><td>±2.3e-308 থেকে ±1.7e308</td><td>বেশি precision দরকার হলে (~15 digit)</td></tr>
          <tr><td><code>char</code></td><td>1 byte</td><td><code>%c</code></td><td>-128 থেকে 127</td><td>একটি character, ASCII code</td></tr>
        </tbody>
      </table>
    </div>

    <div class="subsection"><h3>Modifiers — Data Type বড়/ছোট করা</h3></div>
    <div class="table-wrap">
      <table>
        <thead><tr><th>Modifier</th><th>Effect</th><th>উদাহরণ</th><th>Range পরিবর্তন</th></tr></thead>
        <tbody>
          <tr><td><code>short</code></td><td>Size কমায়</td><td><code>short int s;</code></td><td>2 bytes, -32,768 থেকে 32,767</td></tr>
          <tr><td><code>long</code></td><td>Size বাড়ায়</td><td><code>long int l;</code></td><td>4-8 bytes, অনেক বড় range</td></tr>
          <tr><td><code>unsigned</code></td><td>শুধু positive</td><td><code>unsigned int u;</code></td><td>0 থেকে 4,294,967,295</td></tr>
          <tr><td><code>signed</code></td><td>Positive ও negative (default)</td><td><code>signed int s;</code></td><td>Default behavior</td></tr>
        </tbody>
      </table>
    </div>
  </section>

  <!-- ═══════════════ SECTION 5 ═══════════════ -->
  <section class="section" id="input">
    <div class="section-header">
      <span class="section-num">05</span>
      <h2 class="section-title">User Input — scanf()</h2>
      <span class="section-file">takeInput.c</span>
    </div>

    <div class="definition">
      <strong>scanf() কী:</strong> <code>scanf()</code> হলো C এর built-in function যা keyboard থেকে user এর input পড়ে এবং variable-এ store করে। এটা <code>printf()</code> এর opposite — printf output দেয়, scanf input নেয়।
    </div>

    <div class="code-block">
      <div class="code-header">
        <div class="code-dots"><span class="dot-red"></span><span class="dot-yellow"></span><span class="dot-green"></span></div>
        <span class="code-filename">takeInput.c</span>
        <span class="code-lang">C</span>
      </div>
      <pre><span class="inc">#include</span><span class="str">&lt;stdio.h&gt;</span>

<span class="kw">int</span> <span class="fn">main</span><span class="punc">(){</span>
    <span class="kw">int</span> a<span class="punc">;</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Enter an integer: "</span><span class="punc">);</span>
    <span class="fn">scanf</span><span class="punc">(</span><span class="str">"<span class="fmt">%d</span>"</span>, <span class="op">&amp;</span>a<span class="punc">);</span>

    <span class="kw">char</span> b<span class="punc">;</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Enter a character: "</span><span class="punc">);</span>
    <span class="fn">scanf</span><span class="punc">(</span><span class="str">" <span class="fmt">%c</span>"</span>, <span class="op">&amp;</span>b<span class="punc">);</span>  <span class="cm">// ← space before %c important!</span>

    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Integer: <span class="fmt">%d</span>, Char: <span class="fmt">%c</span>\n"</span>, a, b<span class="punc">);</span>
    <span class="kw">return</span> <span class="num2">0</span><span class="punc">;</span>
<span class="punc">}</span></pre>
    </div>

    <div class="subsection"><h3>scanf() এর Syntax ও গুরুত্বপূর্ণ Concepts</h3></div>
    <div class="table-wrap">
      <table>
        <thead><tr><th>Concept</th><th>ব্যাখ্যা</th><th>উদাহরণ</th></tr></thead>
        <tbody>
          <tr><td><code>&amp;</code> Address-of Operator</td><td>Variable এর memory address pass করে — scanf এই address-এ গিয়ে value রাখে। ছাড়া দিলে program crash করবে!</td><td><code>scanf("%d", &amp;age);</code></td></tr>
          <tr><td>Format Specifier</td><td>কী ধরনের input expect করছি সেটা বলে</td><td><code>"%d"</code> = integer input</td></tr>
          <tr><td><code>" %c"</code> এর আগে space</td><td>আগের input এর <code>\n</code> (newline) consume করে। ছাড়া দিলে character input skip হয়!</td><td><code>scanf(" %c", &amp;ch);</code></td></tr>
          <tr><td>Multiple Input</td><td>একসাথে একাধিক value নেওয়া যায়</td><td><code>scanf("%d %f", &amp;a, &amp;b);</code></td></tr>
        </tbody>
      </table>
    </div>

    <div class="tip warning"><div class="tip-icon">⚠️</div><div><strong>Common Mistake:</strong> char input নেওয়ার আগে <code>" %c"</code> এ space না দিলে আগের Enter চাপার <code>\n</code> character টা input হিসেবে চলে যায়, ফলে character input skip হয়ে যায়।</div></div>
  </section>

  <!-- ═══════════════ SECTION 6 ═══════════════ -->
  <section class="section" id="naming">
    <div class="section-header">
      <span class="section-num">06</span>
      <h2 class="section-title">Naming Rules</h2>
      <span class="section-file">namingRules.c</span>
    </div>

    <div class="definition">
      <strong>Naming Rules কী:</strong> C-তে variable, function বা অন্য identifier এর নাম দেওয়ার কিছু নির্দিষ্ট নিয়ম আছে। এই নিয়ম না মানলে compiler error দেবে।
    </div>

    <div class="table-wrap">
      <table>
        <thead><tr><th>✅ অনুমতি আছে</th><th>❌ অনুমতি নেই</th><th>ভুল উদাহরণ</th><th>কেন ভুল</th></tr></thead>
        <tbody>
          <tr><td>Letters (a-z, A-Z)</td><td>Digit দিয়ে শুরু</td><td><code>1stPlace</code></td><td>নাম digit দিয়ে শুরু হতে পারবে না</td></tr>
          <tr><td>Underscore <code>_</code></td><td>Space</td><td><code>student name</code></td><td>Space allowed না</td></tr>
          <tr><td>Digits (প্রথম char এর পরে)</td><td>Special chars</td><td><code>student@name</code></td><td><code>@</code>, <code>#</code>, <code>$</code> allowed না</td></tr>
          <tr><td>—</td><td>C Keywords</td><td><code>int</code>, <code>return</code></td><td>Reserved words ব্যবহার করা যাবে না</td></tr>
        </tbody>
      </table>
    </div>

    <div class="tip"><div class="tip-icon">⚠️</div><div><strong>Case Sensitive:</strong> C fully case-sensitive। <code>age</code>, <code>Age</code>, এবং <code>AGE</code> তিনটি সম্পূর্ণ আলাদা variable। এটা অনেক common bug এর কারণ।</div></div>

    <div class="subsection"><h3>Naming Conventions — Best Practices</h3></div>
    <div class="table-wrap">
      <table>
        <thead><tr><th>Convention</th><th>উদাহরণ</th><th>কোথায় ব্যবহার করে</th></tr></thead>
        <tbody>
          <tr><td>snake_case</td><td><code>student_age</code>, <code>total_marks</code></td><td>Variables, functions (most common in C)</td></tr>
          <tr><td>camelCase</td><td><code>studentAge</code>, <code>totalMarks</code></td><td>Variables (alternative style)</td></tr>
          <tr><td>UPPER_CASE</td><td><code>MAX_VALUE</code>, <code>PI</code></td><td>Constants (<code>#define</code> বা <code>const</code>)</td></tr>
          <tr><td>Descriptive Names</td><td><code>studentAge</code> না <code>a</code></td><td>সর্বত্র — meaningful নাম দাও</td></tr>
        </tbody>
      </table>
    </div>
  </section>

  <!-- ═══════════════ SECTION 7 ═══════════════ -->
  <section class="section" id="limits">
    <div class="section-header">
      <span class="section-num">07</span>
      <h2 class="section-title">Data Type Limitations</h2>
      <span class="section-file">dataTypeLimit.c</span>
    </div>

    <div class="definition">
      <strong>Limitations কী:</strong> প্রতিটি data type শুধু একটি নির্দিষ্ট range এর value রাখতে পারে। এই range অতিক্রম করলে <strong>overflow</strong> হয় — value unexpected ভাবে wrap around করে।
    </div>

    <div class="table-wrap">
      <table>
        <thead><tr><th>Data Type</th><th>Size</th><th>Minimum</th><th>Maximum</th><th>Precision</th></tr></thead>
        <tbody>
          <tr><td><code>char</code></td><td>1 byte</td><td>-128</td><td>127</td><td>Exact</td></tr>
          <tr><td><code>unsigned char</code></td><td>1 byte</td><td>0</td><td>255</td><td>Exact</td></tr>
          <tr><td><code>short int</code></td><td>2 bytes</td><td>-32,768</td><td>32,767</td><td>Exact</td></tr>
          <tr><td><code>unsigned short</code></td><td>2 bytes</td><td>0</td><td>65,535</td><td>Exact</td></tr>
          <tr><td><code>int</code></td><td>4 bytes</td><td>-2,147,483,648</td><td>2,147,483,647</td><td>Exact</td></tr>
          <tr><td><code>unsigned int</code></td><td>4 bytes</td><td>0</td><td>4,294,967,295</td><td>Exact</td></tr>
          <tr><td><code>long int</code></td><td>8 bytes</td><td>-9,223,372,036,854,775,808</td><td>9,223,372,036,854,775,807</td><td>Exact</td></tr>
          <tr><td><code>float</code></td><td>4 bytes</td><td>1.2e-38</td><td>3.4e38</td><td>~7 digits</td></tr>
          <tr><td><code>double</code></td><td>8 bytes</td><td>2.3e-308</td><td>1.7e308</td><td>~15 digits</td></tr>
          <tr><td><code>long double</code></td><td>10-16 bytes</td><td>3.4e-4932</td><td>1.1e4932</td><td>~19 digits</td></tr>
        </tbody>
      </table>
    </div>

    <div class="subsection"><h3>গুরুত্বপূর্ণ Concepts</h3></div>
    <div class="table-wrap">
      <table>
        <thead><tr><th>Concept</th><th>ব্যাখ্যা</th><th>উদাহরণ</th></tr></thead>
        <tbody>
          <tr><td>Overflow</td><td>Maximum range ছাড়িয়ে যাওয়া — value negative হয়ে wrap করে</td><td><code>int x = 2147483648;</code> → negative value হয়</td></tr>
          <tr><td>Underflow</td><td>Minimum range এর নিচে যাওয়া</td><td>Float বারবার ভাগ করলে 0 হয়ে যায়</td></tr>
          <tr><td>Precision Loss</td><td>Floating point এ exact representation সম্ভব না</td><td><code>0.1 + 0.2 != 0.3</code> (বিখ্যাত floating point bug)</td></tr>
          <tr><td>Truncation</td><td>Float থেকে int এ রাখলে decimal অংশ কেটে যায়</td><td><code>int x = 5.9;</code> → x = 5</td></tr>
        </tbody>
      </table>
    </div>

    <div class="tip warning"><div class="tip-icon">⚠️</div><div><strong>Overflow Trap:</strong> <code>int a = 2147483647; a++;</code> করলে <code>a</code> এর মান হবে <code>-2147483648</code>! এটা bug হিসেবে খুবই কঠিন খুঁজে পেতে। বড় সংখ্যার জন্য <code>long</code> বা <code>long long</code> ব্যবহার করো।</div></div>
  </section>

  <!-- ═══════════════ SECTION 8 ═══════════════ -->
  <section class="section" id="operators">
    <div class="section-header">
      <span class="section-num">08</span>
      <h2 class="section-title">All Operators</h2>
      <span class="section-file">operators.c</span>
    </div>

    <div class="definition">
      <strong>Operator কী:</strong> Operator হলো symbol যা operands (variable বা value) এর উপর operation করে। C-তে অনেক ধরনের operator আছে — arithmetic থেকে bitwise পর্যন্ত।
    </div>

    <div class="op-grid">
      <div class="op-card">
        <div class="op-card-header arith">① Arithmetic Operators</div>
        <table>
          <thead><tr><th>Operator</th><th>কাজ</th><th>Example</th><th>Result</th></tr></thead>
          <tbody>
            <tr><td><code>+</code></td><td>যোগ</td><td>10 + 3</td><td>13</td></tr>
            <tr><td><code>-</code></td><td>বিয়োগ</td><td>10 - 3</td><td>7</td></tr>
            <tr><td><code>*</code></td><td>গুণ</td><td>10 * 3</td><td>30</td></tr>
            <tr><td><code>/</code></td><td>ভাগ</td><td>10 / 3</td><td>3 (দশমিক কাটা)</td></tr>
            <tr><td><code>%</code></td><td>ভাগশেষ</td><td>10 % 3</td><td>1</td></tr>
          </tbody>
        </table>
      </div>

      <div class="op-card">
        <div class="op-card-header relat">② Relational Operators</div>
        <table>
          <thead><tr><th>Operator</th><th>অর্থ</th><th>Example</th><th>Result</th></tr></thead>
          <tbody>
            <tr><td><code>==</code></td><td>সমান</td><td>10 == 3</td><td>0 (false)</td></tr>
            <tr><td><code>!=</code></td><td>সমান না</td><td>10 != 3</td><td>1 (true)</td></tr>
            <tr><td><code>&gt;</code></td><td>বড়</td><td>10 &gt; 3</td><td>1 (true)</td></tr>
            <tr><td><code>&lt;</code></td><td>ছোট</td><td>10 &lt; 3</td><td>0 (false)</td></tr>
            <tr><td><code>&gt;=</code></td><td>বড় বা সমান</td><td>10 &gt;= 10</td><td>1 (true)</td></tr>
            <tr><td><code>&lt;=</code></td><td>ছোট বা সমান</td><td>10 &lt;= 3</td><td>0 (false)</td></tr>
          </tbody>
        </table>
      </div>

      <div class="op-card">
        <div class="op-card-header logic">③ Logical Operators</div>
        <table>
          <thead><tr><th>Operator</th><th>অর্থ</th><th>Truth Table</th></tr></thead>
          <tbody>
            <tr><td><code>&amp;&amp;</code></td><td>AND — দুটোই true হলে</td><td>T&amp;&amp;T=T, T&amp;&amp;F=F</td></tr>
            <tr><td><code>||</code></td><td>OR — যেকোনো একটি true হলে</td><td>T||F=T, F||F=F</td></tr>
            <tr><td><code>!</code></td><td>NOT — opposite করে</td><td>!T=F, !F=T</td></tr>
          </tbody>
        </table>
      </div>

      <div class="op-card">
        <div class="op-card-header bitw">④ Bitwise Operators</div>
        <table>
          <thead><tr><th>Operator</th><th>নাম</th><th>উদাহরণ</th></tr></thead>
          <tbody>
            <tr><td><code>&amp;</code></td><td>AND</td><td>5&amp;3 = 1 (101&amp;011=001)</td></tr>
            <tr><td><code>|</code></td><td>OR</td><td>5|3 = 7 (101|011=111)</td></tr>
            <tr><td><code>^</code></td><td>XOR</td><td>5^3 = 6 (101^011=110)</td></tr>
            <tr><td><code>~</code></td><td>NOT</td><td>~5 = complement</td></tr>
            <tr><td><code>&lt;&lt;</code></td><td>Left Shift</td><td>5&lt;&lt;1 = 10</td></tr>
            <tr><td><code>&gt;&gt;</code></td><td>Right Shift</td><td>5&gt;&gt;1 = 2</td></tr>
          </tbody>
        </table>
      </div>

      <div class="op-card">
        <div class="op-card-header assign">⑤ Assignment Operators</div>
        <table>
          <thead><tr><th>Operator</th><th>Example</th><th>Equivalent</th></tr></thead>
          <tbody>
            <tr><td><code>=</code></td><td>x = 5</td><td>x = 5</td></tr>
            <tr><td><code>+=</code></td><td>x += 2</td><td>x = x + 2</td></tr>
            <tr><td><code>-=</code></td><td>x -= 2</td><td>x = x - 2</td></tr>
            <tr><td><code>*=</code></td><td>x *= 2</td><td>x = x * 2</td></tr>
            <tr><td><code>/=</code></td><td>x /= 2</td><td>x = x / 2</td></tr>
            <tr><td><code>%=</code></td><td>x %= 2</td><td>x = x % 2</td></tr>
          </tbody>
        </table>
      </div>
    </div>

    <div class="subsection"><h3>⑥ Increment & Decrement — গুরুত্বপূর্ণ পার্থক্য</h3></div>
    <div class="table-wrap">
      <table>
        <thead><tr><th>Operator</th><th>ধরন</th><th>Example</th><th>কী হয়</th></tr></thead>
        <tbody>
          <tr><td><code>x++</code></td><td>Post-increment</td><td><code>printf("%d", x++);</code></td><td>আগে current value use করে, তারপর 1 বাড়ায়</td></tr>
          <tr><td><code>++x</code></td><td>Pre-increment</td><td><code>printf("%d", ++x);</code></td><td>আগে 1 বাড়ায়, তারপর নতুন value use করে</td></tr>
          <tr><td><code>x--</code></td><td>Post-decrement</td><td><code>printf("%d", x--);</code></td><td>আগে current value use করে, তারপর 1 কমায়</td></tr>
          <tr><td><code>--x</code></td><td>Pre-decrement</td><td><code>printf("%d", --x);</code></td><td>আগে 1 কমায়, তারপর নতুন value use করে</td></tr>
        </tbody>
      </table>
    </div>

    <div class="subsection"><h3>⑦ Ternary Operator — সংক্ষিপ্ত if-else</h3></div>
    <div class="code-block">
      <div class="code-header">
        <div class="code-dots"><span class="dot-red"></span><span class="dot-yellow"></span><span class="dot-green"></span></div>
        <span class="code-filename">Syntax</span>
        <span class="code-lang">C</span>
      </div>
      <pre><span class="cm">// Syntax: condition ? value_if_true : value_if_false</span>
<span class="kw">int</span> max <span class="op">=</span> <span class="punc">(</span>a <span class="op">&gt;</span> b<span class="punc">)</span> <span class="op">?</span> a <span class="op">:</span> b<span class="punc">;</span>
<span class="cm">// a > b হলে max = a, না হলে max = b</span>

<span class="cm">// sizeof operator</span>
<span class="fn">printf</span><span class="punc">(</span><span class="str">"int size: <span class="fmt">%zu</span> bytes\n"</span>, <span class="kw">sizeof</span><span class="punc">(</span><span class="kw">int</span><span class="punc">));</span>  <span class="cm">// Output: 4</span></pre>
    </div>

    <div class="subsection"><h3>Operator Precedence — কোনটা আগে calculate হয়</h3></div>
    <div class="tip info"><div class="tip-icon">📌</div><div>উপরের row এর operator আগে execute হয়। Precedence মনে না থাকলে সবসময় <strong>parentheses <code>()</code></strong> ব্যবহার করো — এটা সবচেয়ে নিরাপদ।</div></div>
    <div class="table-wrap">
      <table class="prec-table">
        <thead><tr><th>Level</th><th>Operators</th><th>Associativity</th></tr></thead>
        <tbody>
          <tr><td>1 (সর্বোচ্চ)</td><td><code>()</code> <code>[]</code> <code>.</code> <code>-&gt;</code></td><td>Left → Right</td></tr>
          <tr><td>2</td><td><code>++</code> <code>--</code> <code>!</code> <code>~</code> <code>sizeof</code> (unary)</td><td>Right → Left</td></tr>
          <tr><td>3</td><td><code>*</code> <code>/</code> <code>%</code></td><td>Left → Right</td></tr>
          <tr><td>4</td><td><code>+</code> <code>-</code></td><td>Left → Right</td></tr>
          <tr><td>5</td><td><code>&lt;&lt;</code> <code>&gt;&gt;</code></td><td>Left → Right</td></tr>
          <tr><td>6</td><td><code>&lt;</code> <code>&lt;=</code> <code>&gt;</code> <code>&gt;=</code></td><td>Left → Right</td></tr>
          <tr><td>7</td><td><code>==</code> <code>!=</code></td><td>Left → Right</td></tr>
          <tr><td>8–10</td><td><code>&amp;</code> → <code>^</code> → <code>|</code></td><td>Left → Right</td></tr>
          <tr><td>11</td><td><code>&amp;&amp;</code></td><td>Left → Right</td></tr>
          <tr><td>12</td><td><code>||</code></td><td>Left → Right</td></tr>
          <tr><td>13</td><td><code>?:</code></td><td>Right → Left</td></tr>
          <tr><td>14</td><td><code>=</code> <code>+=</code> <code>-=</code> ইত্যাদি</td><td>Right → Left</td></tr>
          <tr><td>15 (সর্বনিম্ন)</td><td><code>,</code></td><td>Left → Right</td></tr>
        </tbody>
      </table>
    </div>
  </section>

  <!-- ═══════════════ SECTION 9 ═══════════════ -->
  <section class="section" id="conditions">
    <div class="section-header">
      <span class="section-num">09</span>
      <h2 class="section-title">Conditional Statements</h2>
      <span class="section-file">AllCondition.c</span>
    </div>

    <div class="definition">
      <strong>Conditional Statement কী:</strong> Conditional statement প্রোগ্রামকে সিদ্ধান্ত নিতে দেয়। কোনো condition সত্য হলে এক ব্লক চলে, মিথ্যা হলে অন্য ব্লক। এটা ছাড়া প্রোগ্রাম সব সময় একই কাজ করতো।
    </div>

    <div class="subsection"><h3>① if Statement</h3></div>
    <div class="code-block">
      <div class="code-header">
        <div class="code-dots"><span class="dot-red"></span><span class="dot-yellow"></span><span class="dot-green"></span></div>
        <span class="code-filename">Syntax</span><span class="code-lang">C</span>
      </div>
      <pre><span class="kw">if</span> <span class="punc">(</span>condition<span class="punc">) {</span>
    <span class="cm">// condition true (non-zero) হলে এই block চলে</span>
<span class="punc">}</span></pre>
    </div>
    <div class="table-wrap"><table><thead><tr><th>বিষয়</th><th>বিবরণ</th></tr></thead><tbody>
      <tr><td>Purpose</td><td>Single decision — condition সত্য হলে code চলে</td></tr>
      <tr><td>Condition</td><td>যেকোনো expression যা non-zero (true) বা 0 (false) দেয়</td></tr>
      <tr><td>False হলে</td><td>if block সম্পূর্ণ skip হয়</td></tr>
    </tbody></table></div>

    <div class="subsection"><h3>② if-else Statement</h3></div>
    <div class="code-block">
      <div class="code-header">
        <div class="code-dots"><span class="dot-red"></span><span class="dot-yellow"></span><span class="dot-green"></span></div>
        <span class="code-filename">Syntax</span><span class="code-lang">C</span>
      </div>
      <pre><span class="kw">if</span> <span class="punc">(</span>condition<span class="punc">) {</span>
    <span class="cm">// condition true হলে</span>
<span class="punc">}</span> <span class="kw">else</span> <span class="punc">{</span>
    <span class="cm">// condition false হলে</span>
<span class="punc">}</span></pre>
    </div>

    <div class="subsection"><h3>③ else-if Ladder</h3></div>
    <div class="code-block">
      <div class="code-header">
        <div class="code-dots"><span class="dot-red"></span><span class="dot-yellow"></span><span class="dot-green"></span></div>
        <span class="code-filename">Example — Grade System</span><span class="code-lang">C</span>
      </div>
      <pre><span class="kw">if</span> <span class="punc">(</span>marks <span class="op">&gt;=</span> <span class="num2">90</span><span class="punc">) {</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Grade: A+"</span><span class="punc">);</span>
<span class="punc">}</span> <span class="kw">else if</span> <span class="punc">(</span>marks <span class="op">&gt;=</span> <span class="num2">80</span><span class="punc">) {</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Grade: A"</span><span class="punc">);</span>
<span class="punc">}</span> <span class="kw">else if</span> <span class="punc">(</span>marks <span class="op">&gt;=</span> <span class="num2">70</span><span class="punc">) {</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Grade: B"</span><span class="punc">);</span>
<span class="punc">}</span> <span class="kw">else</span> <span class="punc">{</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Grade: F"</span><span class="punc">);</span>
<span class="punc">}</span>
<span class="cm">// প্রথম true condition এর block চলে, বাকি সব skip হয়</span></pre>
    </div>

    <div class="subsection"><h3>④ Switch-Case Statement</h3></div>
    <div class="code-block">
      <div class="code-header">
        <div class="code-dots"><span class="dot-red"></span><span class="dot-yellow"></span><span class="dot-green"></span></div>
        <span class="code-filename">Syntax</span><span class="code-lang">C</span>
      </div>
      <pre><span class="kw">switch</span> <span class="punc">(</span>expression<span class="punc">) {</span>
    <span class="kw">case</span> <span class="num2">1</span><span class="punc">:</span>
        <span class="cm">// code</span>
        <span class="kw">break</span><span class="punc">;</span>     <span class="cm">// ← MUST! না দিলে পরের case-ও চলবে</span>
    <span class="kw">case</span> <span class="num2">2</span><span class="punc">:</span>
        <span class="cm">// code</span>
        <span class="kw">break</span><span class="punc">;</span>
    <span class="kw">default</span><span class="punc">:</span>
        <span class="cm">// কোনো case না মিললে</span>
<span class="punc">}</span></pre>
    </div>

    <div class="table-wrap"><table><thead><tr><th>বিষয়</th><th>নিয়ম</th></tr></thead><tbody>
      <tr><td>Expression</td><td>Integer বা char হতে হবে — float allowed না</td></tr>
      <tr><td>Case values</td><td>Constant হতে হবে, variable allowed না</td></tr>
      <tr><td>break</td><td>ছাড়া দিলে পরের case-এ "fall-through" হয় — সেটা bug তৈরি করে</td></tr>
      <tr><td>default</td><td>Optional — কোনো case না মিললে চলে</td></tr>
    </tbody></table></div>

    <div class="tip warning"><div class="tip-icon">⚠️</div><div><strong>Fall-through Bug:</strong> <code>break</code> না দিলে matching case এর পরের সব case-ও execute হয়। এটা C-এর একটা classic bug। সবসময় <code>break</code> দাও।</div></div>

    <div class="subsection"><h3>⑤ Nested if — if এর ভেতর if</h3></div>
    <div class="code-block">
      <div class="code-header">
        <div class="code-dots"><span class="dot-red"></span><span class="dot-yellow"></span><span class="dot-green"></span></div>
        <span class="code-filename">Example</span><span class="code-lang">C</span>
      </div>
      <pre><span class="kw">if</span> <span class="punc">(</span>age <span class="op">&gt;=</span> <span class="num2">18</span><span class="punc">) {</span>
    <span class="kw">if</span> <span class="punc">(</span>hasID <span class="op">==</span> <span class="num2">1</span><span class="punc">) {</span>
        <span class="fn">printf</span><span class="punc">(</span><span class="str">"Entry allowed"</span><span class="punc">);</span>
    <span class="punc">}</span> <span class="kw">else</span> <span class="punc">{</span>
        <span class="fn">printf</span><span class="punc">(</span><span class="str">"Need ID"</span><span class="punc">);</span>
    <span class="punc">}</span>
<span class="punc">}</span> <span class="kw">else</span> <span class="punc">{</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Too young"</span><span class="punc">);</span>
<span class="punc">}</span></pre>
    </div>
  </section>

  <!-- ═══════════════ SECTION 10 ═══════════════ -->
  <section class="section" id="loops">
    <div class="section-header">
      <span class="section-num">10</span>
      <h2 class="section-title">Loops</h2>
      <span class="section-file">AllLoop.c</span>
    </div>

    <div class="definition">
      <strong>Loop কী:</strong> Loop একটি code block বারবার execute করার উপায়। যতক্ষণ condition সত্য থাকে ততক্ষণ চলতে থাকে। Loop ছাড়া repetitive কাজ করতে একই code হাজারবার লিখতে হতো।
    </div>

    <div class="subsection"><h3>তিন ধরনের Loop এর পার্থক্য</h3></div>
    <div class="loop-compare">
      <div class="loop-card">
        <h4 class="for-c">for Loop</h4>
        <div class="loop-feature"><span class="lk">কখন ব্যবহার</span><span class="lv">Known count</span></div>
        <div class="loop-feature"><span class="lk">Condition check</span><span class="lv">Before execution</span></div>
        <div class="loop-feature"><span class="lk">Min executions</span><span class="lv">0 বার</span></div>
        <div class="loop-feature"><span class="lk">Update location</span><span class="lv">Header-এ</span></div>
      </div>
      <div class="loop-card">
        <h4 class="while-c">while Loop</h4>
        <div class="loop-feature"><span class="lk">কখন ব্যবহার</span><span class="lv">Unknown count</span></div>
        <div class="loop-feature"><span class="lk">Condition check</span><span class="lv">Before execution</span></div>
        <div class="loop-feature"><span class="lk">Min executions</span><span class="lv">0 বার</span></div>
        <div class="loop-feature"><span class="lk">Update location</span><span class="lv">Body-তে</span></div>
      </div>
      <div class="loop-card">
        <h4 class="dowhile-c">do-while Loop</h4>
        <div class="loop-feature"><span class="lk">কখন ব্যবহার</span><span class="lv">Menu / retry</span></div>
        <div class="loop-feature"><span class="lk">Condition check</span><span class="lv">After execution</span></div>
        <div class="loop-feature"><span class="lk">Min executions</span><span class="lv">কমপক্ষে 1 বার</span></div>
        <div class="loop-feature"><span class="lk">Update location</span><span class="lv">Body-তে</span></div>
      </div>
    </div>

    <div class="subsection"><h3>① for Loop</h3></div>
    <div class="code-block">
      <div class="code-header">
        <div class="code-dots"><span class="dot-red"></span><span class="dot-yellow"></span><span class="dot-green"></span></div>
        <span class="code-filename">for Loop</span><span class="code-lang">C</span>
      </div>
      <pre><span class="cm">// Syntax: for(initialization; condition; update)</span>
<span class="kw">for</span> <span class="punc">(</span><span class="kw">int</span> i <span class="op">=</span> <span class="num2">1</span><span class="punc">;</span> i <span class="op">&lt;=</span> <span class="num2">5</span><span class="punc">;</span> i<span class="op">++</span><span class="punc">) {</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"<span class="fmt">%d</span> "</span>, i<span class="punc">);</span>
<span class="punc">}</span>
<span class="cm">// Output: 1 2 3 4 5</span>
<span class="cm">// Flow: Init(i=1) → Check(i≤5) → Body → Update(i++) → Check → ...</span></pre>
    </div>

    <div class="subsection"><h3>② while Loop</h3></div>
    <div class="code-block">
      <div class="code-header">
        <div class="code-dots"><span class="dot-red"></span><span class="dot-yellow"></span><span class="dot-green"></span></div>
        <span class="code-filename">while Loop</span><span class="code-lang">C</span>
      </div>
      <pre><span class="kw">int</span> i <span class="op">=</span> <span class="num2">1</span><span class="punc">;</span>
<span class="kw">while</span> <span class="punc">(</span>i <span class="op">&lt;=</span> <span class="num2">5</span><span class="punc">) {</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"<span class="fmt">%d</span> "</span>, i<span class="punc">);</span>
    i<span class="op">++</span><span class="punc">;</span>   <span class="cm">// update ভুললে infinite loop!</span>
<span class="punc">}</span>
<span class="cm">// প্রথমে condition check, তারপর body — condition false হলে 0 বারও চলে না</span></pre>
    </div>

    <div class="subsection"><h3>③ do-while Loop</h3></div>
    <div class="code-block">
      <div class="code-header">
        <div class="code-dots"><span class="dot-red"></span><span class="dot-yellow"></span><span class="dot-green"></span></div>
        <span class="code-filename">do-while Loop</span><span class="code-lang">C</span>
      </div>
      <pre><span class="kw">int</span> choice<span class="punc">;</span>
<span class="kw">do</span> <span class="punc">{</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"Enter 1 to continue, 0 to exit: "</span><span class="punc">);</span>
    <span class="fn">scanf</span><span class="punc">(</span><span class="str">"<span class="fmt">%d</span>"</span>, <span class="op">&amp;</span>choice<span class="punc">);</span>
<span class="punc">}</span> <span class="kw">while</span> <span class="punc">(</span>choice <span class="op">==</span> <span class="num2">1</span><span class="punc">);</span>
<span class="cm">// Body আগে চলে, তারপর condition check — কমপক্ষে 1 বার চলবেই</span></pre>
    </div>

    <div class="subsection"><h3>④ Nested Loops — Loop এর ভেতর Loop</h3></div>
    <div class="code-block">
      <div class="code-header">
        <div class="code-dots"><span class="dot-red"></span><span class="dot-yellow"></span><span class="dot-green"></span></div>
        <span class="code-filename">Multiplication Table</span><span class="code-lang">C</span>
      </div>
      <pre><span class="kw">for</span> <span class="punc">(</span><span class="kw">int</span> i <span class="op">=</span> <span class="num2">1</span><span class="punc">;</span> i <span class="op">&lt;=</span> <span class="num2">3</span><span class="punc">;</span> i<span class="op">++</span><span class="punc">) {</span>      <span class="cm">// Outer: 3 বার</span>
    <span class="kw">for</span> <span class="punc">(</span><span class="kw">int</span> j <span class="op">=</span> <span class="num2">1</span><span class="punc">;</span> j <span class="op">&lt;=</span> <span class="num2">3</span><span class="punc">;</span> j<span class="op">++</span><span class="punc">) {</span>  <span class="cm">// Inner: প্রতিবার 3 বার</span>
        <span class="fn">printf</span><span class="punc">(</span><span class="str">"<span class="fmt">%d</span> "</span>, i <span class="op">*</span> j<span class="punc">);</span>
    <span class="punc">}</span>
    <span class="fn">printf</span><span class="punc">(</span><span class="str">"\n"</span><span class="punc">);</span>
<span class="punc">}</span>
<span class="cm">// Total iterations = outer × inner = 3 × 3 = 9 বার</span></pre>
    </div>

    <div class="subsection"><h3>⑤ Loop Control Statements</h3></div>
    <div class="table-wrap">
      <table>
        <thead><tr><th>Statement</th><th>কাজ</th><th>উদাহরণ</th><th>কখন ব্যবহার</th></tr></thead>
        <tbody>
          <tr><td><code>break</code></td><td>Loop থেকে সম্পূর্ণ বের হয়ে যায়</td><td><code>if(i==5) break;</code></td><td>কোনো condition পেলে loop বন্ধ করতে</td></tr>
          <tr><td><code>continue</code></td><td>Current iteration skip করে পরেরটায় যায়</td><td><code>if(i==3) continue;</code></td><td>কোনো value skip করতে</td></tr>
        </tbody>
      </table>
    </div>

    <div class="tip warning"><div class="tip-icon">⚠️</div><div><strong>Infinite Loop থেকে সাবধান:</strong> <code>while(1) {}</code> বা update statement ভুললে loop কখনো বন্ধ হবে না। Terminal-এ <code>Ctrl+C</code> চাপলে force stop হয়।</div></div>
  </section>

  <div class="divider"></div>

  <!-- CHECKLIST -->
  <section class="section" id="checklist">
    <div class="section-header">
      <span class="section-num">✓</span>
      <h2 class="section-title">Learning Checklist</h2>
    </div>
    <div class="checklist-grid">
      <div class="check-item"><div class="check-icon">✓</div>Program Structure (#include, main, return)</div>
      <div class="check-item"><div class="check-icon">✓</div>Escape Sequences (\n, \t, \\)</div>
      <div class="check-item"><div class="check-icon">✓</div>Variables (Declaration, Initialization)</div>
      <div class="check-item"><div class="check-icon">✓</div>Data Types (int, float, double, char)</div>
      <div class="check-item"><div class="check-icon">✓</div>Format Specifiers (%d, %f, %c, %lf)</div>
      <div class="check-item"><div class="check-icon">✓</div>User Input — scanf() with &</div>
      <div class="check-item"><div class="check-icon">✓</div>Naming Rules ও Conventions</div>
      <div class="check-item"><div class="check-icon">✓</div>Data Type Limitations ও Overflow</div>
      <div class="check-item"><div class="check-icon">✓</div>Arithmetic Operators (+, -, *, /, %)</div>
      <div class="check-item"><div class="check-icon">✓</div>Relational Operators (==, !=, >, <)</div>
      <div class="check-item"><div class="check-icon">✓</div>Logical Operators (&&, ||, !)</div>
      <div class="check-item"><div class="check-icon">✓</div>Bitwise Operators (&, |, ^, <<, >>)</div>
      <div class="check-item"><div class="check-icon">✓</div>Assignment Operators (=, +=, -= ...)</div>
      <div class="check-item"><div class="check-icon">✓</div>Increment / Decrement (++, --)</div>
      <div class="check-item"><div class="check-icon">✓</div>Ternary Operator (? :)</div>
      <div class="check-item"><div class="check-icon">✓</div>if, if-else Statements</div>
      <div class="check-item"><div class="check-icon">✓</div>else-if Ladder</div>
      <div class="check-item"><div class="check-icon">✓</div>Nested if</div>
      <div class="check-item"><div class="check-icon">✓</div>switch-case Statement</div>
      <div class="check-item"><div class="check-icon">✓</div>for Loop</div>
      <div class="check-item"><div class="check-icon">✓</div>while Loop</div>
      <div class="check-item"><div class="check-icon">✓</div>do-while Loop</div>
      <div class="check-item"><div class="check-icon">✓</div>Nested Loops</div>
      <div class="check-item"><div class="check-icon">✓</div>break ও continue</div>
    </div>
  </section>

  <!-- PRO TIPS -->
  <section class="section" id="tips">
    <div class="section-header">
      <span class="section-num">💡</span>
      <h2 class="section-title">Pro Tips</h2>
    </div>
    <div class="tips-list">
      <div class="pro-tip"><span class="tip-num">01</span><div><strong>সবসময় variable initialize করো</strong> <span>— uninitialized variable-এ garbage value থাকে যা unexpected bug তৈরি করে।</span></div></div>
      <div class="pro-tip"><span class="tip-num">02</span><div><strong>Meaningful নাম দাও</strong> <span>— <code>studentAge</code> অনেক better than <code>a</code>। 6 মাস পরে নিজেও বুঝতে পারবে।</span></div></div>
      <div class="pro-tip"><span class="tip-num">03</span><div><strong>char input এ space দাও</strong> <span>— <code>scanf(" %c", &ch);</code> এ space দিতে ভুলো না, নাহলে newline character input হবে।</span></div></div>
      <div class="pro-tip"><span class="tip-num">04</span><div><strong>switch-এ break দাও</strong> <span>— প্রতিটি case এর শেষে <code>break;</code> দাও, fall-through bug অনেক কষ্টে খুঁজে পেতে হয়।</span></div></div>
      <div class="pro-tip"><span class="tip-num">05</span><div><strong>Loop update ভুলো না</strong> <span>— while loop এ update statement ভুললে infinite loop হয়, program hang করে।</span></div></div>
      <div class="pro-tip"><span class="tip-num">06</span><div><strong>Overflow check করো</strong> <span>— বড় সংখ্যার জন্য <code>int</code> এর বদলে <code>long long</code> ব্যবহার করো।</span></div></div>
      <div class="pro-tip"><span class="tip-num">07</span><div><strong>Parentheses ব্যবহার করো</strong> <span>— Operator precedence মনে না থাকলে <code>()</code> দিয়ে explicitly বলো কোনটা আগে হবে।</span></div></div>
      <div class="pro-tip"><span class="tip-num">08</span><div><strong>Comment লেখো</strong> <span>— <code>// এক লাইন</code> বা <code>/* একাধিক লাইন */</code> — জটিল logic এ সবসময় explain করো।</span></div></div>
      <div class="pro-tip"><span class="tip-num">09</span><div><strong>== আর = ভুল করো না</strong> <span>— <code>if(a = 5)</code> সবসময় true হবে কারণ এটা assignment। <code>if(a == 5)</code> comparison।</span></div></div>
      <div class="pro-tip"><span class="tip-num">10</span><div><strong>Compile করে warning দেখো</strong> <span>— <code>gcc -Wall file.c</code> দিয়ে compile করলে সব warning দেখা যায় যা bug খুঁজতে সাহায্য করে।</span></div></div>
    </div>
  </section>

  <!-- NEXT STEPS -->
  <section class="section" id="next">
    <div class="section-header">
      <span class="section-num">→</span>
      <h2 class="section-title">Next Steps</h2>
    </div>
    <div class="next-grid">
      <div class="next-card"><div class="icon">🔧</div><h4>Functions</h4><p>Code reusability, modular programming</p></div>
      <div class="next-card"><div class="icon">📦</div><h4>Arrays</h4><p>একই type এর multiple data এক জায়গায়</p></div>
      <div class="next-card"><div class="icon">🔗</div><h4>Pointers</h4><p>Direct memory access, dynamic memory</p></div>
      <div class="next-card"><div class="icon">📝</div><h4>Strings</h4><p>Text manipulation, string functions</p></div>
      <div class="next-card"><div class="icon">🏗️</div><h4>Structures</h4><p>Custom data types, records তৈরি</p></div>
      <div class="next-card"><div class="icon">💾</div><h4>File I/O</h4><p>Data persistence, file handling</p></div>
      <div class="next-card"><div class="icon">🧮</div><h4>Dynamic Memory</h4><p>malloc(), calloc(), free()</p></div>
      <div class="next-card"><div class="icon">⚙️</div><h4>Preprocessor</h4><p>Macros, conditional compilation</p></div>
    </div>
  </section>

</main>

<!-- FOOTER -->
<footer class="footer">
  <div class="footer-logo">C Programming</div>
  <p>Complete Fundamentals Reference · Theory-First Guide</p>
  <p style="margin-top: 8px;">Last Updated: 2026 · Happy Coding! 🚀</p>
</footer>

</body>
</html>
