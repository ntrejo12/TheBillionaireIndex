<H1> COP3530 - Project 3 TheBillionaireIndex</h1>

<H2> Top-K Billionaire Sorter</h2>
This project implements and compares two classic sorting algorithms 
— <b>Heap Sort</b> and <b>Merge Sort</b> — to identify the <i>top-k 
wealthiest individuals</i> from Forbes’ annual <i>World’s Billionaires</i> 
rankings dataset (2002–2023). The project evaluates the efficiency of 
these algorithms in large-scale, real-world financial data.


<H2> Problem Statement </H2>

In financial analysis, economics, and media rankings, determining the
top-k wealthiest individuals in a given year is a common yet 
computationally challenging task. Sorting the entire dataset to extract
only a small subset of key results becomes inefficient as dataset sizes
grow. Our project addresses this by implementing and comparing sorting 
algorithms optimized for top-k selection.

<H2> Features Implemented </H2>

<ul>
  <li>Users can input a specific year and k-value to dynamically retrieve the top-k richest individuals for that year.</li>
  <li>Both Heap Sort and Merge Sort are implemented.</li>
  <li>Execution time for each algorithm is displayed for comparison purposes.</li>
  <li>Output is consistent across both sorting approaches.</li>
</ul>

<H2> How to Use This Program </H2>

Follow these steps to compile and run the Top-K Billionaire Index:

<ol>
  <li>Ensure you have CMake and a <b>C++ compiler</b> installed (e.g., CLion).</li>
  <li>Download the project zip file or clone the project.</li>
  <li>Open the project and build it</li>
  <li>The program will compile two executables:</li>
    <ul>
      <li><code>heap_index</code> — runs the Heap Sort implementation</li>
      <li><code>merge_index</code> — runs the Merge Sort implementation</li>
    </ul>
  <li>Run either program</li>
  <li>When prompted, enter a year (e.g., 2020) and a value for k (e.g., 5).</li>
</ol>

<H2> Sample Output </H2>

<b>[Heap Sort] Top 5 Richest in 2020</b>
<pre>
1. Jeff Bezos  
   - Year: 2020  
   - Net Worth: $3,108,630,000  
   - Age: 58  
   - Company: Amazon  
   - Location: Seattle, Washington, United States

2. Bill Gates  
   - Year: 2020  
   - Net Worth: $2,695,980,000  
   - Age: 66  
   - Company: Microsoft  
   - Location: Medina, Washington, United States
...
</pre>

<H2> Citation </H2>

<ul>
  <li>GeeksforGeeks. (n.d.). <i>Heap Sort</i>. https://www.geeksforgeeks.org/heap-sort/</li>
  <li>GeeksforGeeks. (n.d.). <i>Merge Sort</i>. https://www.geeksforgeeks.org/merge-sort/</li>
  <li>Salim Wid. (2023). <i>Global Billionaire Wealth and Sources (2002–2023)</i>. Kaggle. https://www.kaggle.com/datasets/salimwid/global-billionaire-wealth-and-sources-2002-2023</li>
</ul>
