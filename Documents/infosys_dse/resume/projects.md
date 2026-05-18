# PROJECTS

## Project 1: SEO Catalyst (AI-Driven Content Pipeline & SEO Platform)

### 1. The Core Concept (What is it?)
SEO Catalyst is a modern web application designed to help digital marketers and content creators analyze their websites. Unlike traditional SEO tools that just look at keywords, this platform uses AI to perform Answer Engine Optimization (AEO)—evaluating how well a piece of content would be cited by an AI chatbot (like ChatGPT or Gemini).

### 2. Core Functionalities & Use Cases
* **Real-Time Technical SEO Auditing:** The platform crawls a target website and instantly flags technical issues (e.g., missing tags, broken links, structural flaws).
* **AI-Driven AEO Scoring:** It takes the scraped website content and feeds it into the Gemini AI, which grades the content on how well it answers specific user queries.
* **Competitive Gap Analysis:** It compares a user's content against competitors to find missing topics or keywords.
* **Automated Review Workflows:** Users can track their content's performance over time through interactive dashboards.
* **Use Case:** An SEO agency uses the tool to scan a client's blog, get an AI score on the content's quality, and assign a writer (via role-based access) to fix the gaps.

### 3. Design Approach & Architecture
The architecture is designed around a decoupled, serverless approach to handle heavy data processing without slowing down the user experience.
* **The Frontend Layer:** Built to be highly interactive and responsive, using over 20 reusable UI components to construct the scoring dashboards.
* **The Data & Auth Layer:** Centralized around a secure backend database that strictly enforces who can see what using Role-Based Access Control (RBAC).
* **The AI Processing Layer:** An asynchronous workflow that takes the heavy text data scraped from websites and securely passes it to an external LLM for analysis.

### 4. Technology Stack (And Why You Chose It)
* **Next.js:** Chosen for its ability to handle both server-side API routes (for secure data fetching) and client-side rendering (for snappy dashboards).
* **TypeScript:** Essential for a data-heavy application. It provided type safety when handling large, unpredictable web-crawling data payloads, preventing runtime errors.
* **Supabase:** Chosen as the backend-as-a-service (BaaS) for its built-in PostgreSQL database and seamless integration of user authentication and RBAC.
* **Gemini API:** The core engine for the AEO scoring, chosen for its advanced natural language processing capabilities.
* **Tailwind CSS:** Allowed for the rapid development of a consistent, responsive UI system without writing heavy custom CSS files.
* **Vercel:** Used for deployment to enable a seamless Continuous Integration/Continuous Deployment (CI/CD) pipeline.

### 5. Implementation Workflow (How Data Moves)
1. **Authentication:** A user logs into the Next.js app. Supabase verifies their identity and checks their RBAC level (e.g., Admin vs. Viewer).
2. **Data Ingestion:** The user inputs a URL. The backend triggers a web-crawling function to extract the HTML and text from that page.
3. **Processing:** The extracted payload is formatted via TypeScript to ensure the data structure is correct.
4. **AI Analysis:** The formatted text is sent via API call to Gemini with a specific prompt asking it to evaluate the content's AEO.
5. **Rendering:** The Gemini API returns a score and analysis. This data is saved to the Supabase database and instantly pushed to the frontend, updating the Tailwind-styled interactive dashboards.

---

### Interview Defense: Data Extraction and Server-Side Processing

#### Part 1: How You Scraped the Data (The Implementation Story)
When asked, *"How did you actually build the web crawler?"*, explain it as a robust, step-by-step pipeline happening on your Node.js/Next.js backend:

1. **The Request:** The user submits a target URL on the frontend. The Next.js frontend sends this URL to a secure Next.js Serverless API route.
2. **Fetching the HTML:** On the backend, I used a standard HTTP client (like `Axios` or the native `fetch` API) to send a GET request to the target URL and retrieve the raw HTML document.
3. **Parsing the DOM:** Because raw HTML is massive and messy, I used an HTML parsing library in Node.js (typically **Cheerio** is the industry standard for this) to load the HTML into a virtual DOM.
4. **Targeted Extraction:** Instead of scraping everything, I wrote specific traversal logic to target SEO-relevant tags. I extracted the `<title>`, `<meta>` descriptions, `<h1>` to `<h6>` hierarchies, and the core `<p>` text bodies.
5. **Sanitization:** Crucially, I stripped out all `<script>`, `<style>`, and `<svg>` tags. This reduced the payload size dramatically, ensuring I only sent clean, readable text to the Gemini API.

#### Part 2: Key Challenges & Your Defense Strategy

* **Challenge 1: The Vercel/Serverless Timeout Limit**
  * **The Problem:** Serverless functions (like Vercel API routes) have strict timeout limits. If you scrape a massive website, clean the data, and wait for the Gemini AI, the server will time out.
  * **The Defense:** "To prevent server bottlenecks, I handled the process asynchronously. The initial API call triggered the scraping and immediately returned a 'processing' state to the UI. The heavy lifting—parsing the large data payload and waiting on the Gemini API response—happened in the background. Once the database (Supabase) was updated with the AI score, the frontend UI updated."

* **Challenge 2: LLM Context Window Limits (Token Limits)**
  * **The Problem:** You cannot feed an infinitely long webpage into an AI. Gemini has a maximum token limit for its context window.
  * **The Defense:** "A major challenge was dealing with massive webpages that exceeded the AI's token limit. To solve this, after parsing the DOM, I implemented a chunking strategy. I split the sanitized text into manageable, token-safe blocks before sending them to the Gemini API. This ensured the API requests never failed due to payload size."

* **Challenge 3: Unpredictable DOM Structures**
  * **The Problem:** Not all websites are built well. Some are missing `<h1>` tags or have massively nested `<div>` chains that break generic scrapers.
  * **The Defense:** "Because web data is highly unstructured, the scraper frequently encountered missing tags or malformed HTML. I defended against this by strictly typing my data structures using TypeScript. I implemented fallback values (null checks) so that if a page was missing a meta tag, the scraper wouldn't crash the server; it would simply log the missing data and continue the SEO audit."

#### Specific Tooling: Which Node.js library did you use?
> **Your Answer:** "I used **Cheerio**. Since I didn't need to render a full headless browser or execute client-side JavaScript—which would have slowed down the API response time—I didn't use something heavy like Puppeteer. Instead, I used the native `fetch` API to grab the raw HTML document and then loaded it into Cheerio. Cheerio provided a lightweight, jQuery-like syntax that allowed me to easily traverse the DOM. Specifically, I used it to target and strip out all `<script>`, `<style>`, `<nav>`, and `<footer>` tags. Once the noise was removed, I extracted just the clean `<body>` text. This approach was highly efficient and ensured the text payload I sent to the Gemini API stayed perfectly within its token limits."

---
---

## Project 2: ResumeGuide (AI-Assisted Resume Builder)

### 1. The Core Concept (What is it?)
ResumeGuide is an AI-powered career platform designed to automate and enhance the job preparation process. Rather than just being a static form that generates a PDF, it acts as an intelligent career coach. It generates optimized resume content, facilitates interactive mock interviews, and autonomously tracks real-time industry insights (like salary trends and required skills).

### 2. Core Functionalities & Use Cases
* **AI-Assisted Resume & Cover Letter Generation:** Users input basic details, and the platform uses the Gemini API to generate professional, tailored bullet points and complete cover letters.
* **Live Resume Previews & High-Fidelity PDF Exports:** The user interface updates in real-time as content is added, allowing users to export a perfectly formatted PDF instantly.
* **Interactive Mock Interviews:** A dedicated module where users can practice interview questions and receive AI-driven feedback on their performance.
* **Automated Industry Insights:** A background system autonomously fetches and updates data on industry trends, salary ranges, and market outlooks every week.
* **Use Case:** A fresh graduate uses the platform to instantly generate a tech-focused resume, practice answering full-stack developer interview questions, and check the current median salary for their target role.

### 3. Design Approach & Architecture
The architecture is designed around an **event-driven, serverless model**.
* **The Auth & User Layer:** Secured at the edge using Clerk to manage sessions seamlessly.
* **The Core Application Layer:** A Next.js 15 application utilizing React 19, heavily leveraging Server Actions and a robust set of UI components (Tailwind, Radix UI) for a highly interactive frontend.
* **The Background Processing Layer:** Instead of relying on traditional API routes that might time out, heavy tasks (like AI data aggregation and scheduled industry updates) are offloaded to an event-driven queue system using Inngest.
* **The Data Layer:** Handled by a Neon serverless PostgreSQL database, mapped and queried using Prisma ORM.

### 4. Technology Stack (And *Why* You Chose It)
* **React & Next.js (v15):** Chosen for its App Router and Server Components, providing a snappy, SEO-friendly application structure.
* **Gemini 2.5 Flash API:** Selected for its speed and strict JSON-mode capabilities, which are essential for reliably generating structured data (like mock interview results and industry stats).
* **Inngest:** The crucial piece of the backend. Chosen to handle concurrent background jobs and cron schedules without needing to provision a dedicated worker server.
* **Clerk:** Chosen for drop-in, highly secure user authentication that integrates natively with Next.js middleware.
* **Prisma & Neon:** Prisma provides type-safe database queries, and Neon offers a serverless PostgreSQL environment that scales automatically and handles connections efficiently in a serverless environment.
* **html2pdf.js:** Chosen to offload the heavy PDF rendering process to the client's browser, saving massive amounts of server compute time.

### 5. Implementation Workflow (Highlighting the Background Jobs)
Here is exactly how the automated Industry Insights pipeline works:
1. **The Trigger:** I set up an Inngest Cron job configured to run automatically every Sunday at midnight (`0 0 * * 0`).
2. **The Fetch:** The function queries the Prisma database to retrieve a list of all active industries currently being tracked.
3. **The AI Processing:** For each industry, the background worker sends a highly specific, strict-JSON prompt to the Gemini API, asking it to evaluate the current market outlook, growth rates, top skills, and salary bands for that specific sector.
4. **The Update:** The function parses the returned JSON payload and updates the Neon database via Prisma with fresh data. Because this runs via Inngest, it happens entirely asynchronously in the background, ensuring zero impact on user-facing latency.

### 6. Key Challenges & How to Defend Them

* **Challenge 1: Handling Concurrent AI Requests Without Latency**
  * **The Problem:** When multiple users hit the "Generate Resume" or "Start Interview" buttons simultaneously, sending all those requests synchronously through standard Vercel API routes can cause massive bottlenecks.
  * **The Defense:** "To ensure the app could handle concurrent requests without latency, I integrated Inngest. Instead of holding the client connection open while waiting for the Gemini API to generate long-form content, the heavy lifting was offloaded to robust background workflows. This kept the UI highly responsive."

* **Challenge 2: Generating High-Fidelity PDFs at Scale**
  * **The Problem:** Generating a PDF on a server requires spinning up a headless browser (like Puppeteer), which is incredibly slow, memory-intensive, and expensive on serverless platforms.
  * **The Defense:** "I wanted to avoid server bottlenecks completely for PDF generation. I implemented `html2pdf.js` alongside React to render the high-fidelity exports directly within the user's browser. This entirely eliminated server compute costs for PDF generation and allowed users to download their resumes instantly."

* **Challenge 3: Forcing AI to Return Usable Data**
  * **The Problem:** LLMs naturally want to talk. If you ask an AI for industry data, it might return a paragraph of text instead of the strict database-ready format you need.
  * **The Defense:** "When building the automated industry insights worker, getting clean data was tough. I solved this by explicitly instructing the Gemini 2.5 model to return *only* a specific JSON structure, bypassing markdown. I then wrote backend logic to strip any rogue formatting before parsing the JSON and injecting it into the Prisma database. This ensured data integrity."

### 7. Outcome
The final product is a highly interactive, full-stack career platform deployed on Vercel. It flawlessly handles asynchronous AI workloads, secure user authentication, and automated database updates while maintaining a latency-free, responsive user interface comprising 25+ reusable components.