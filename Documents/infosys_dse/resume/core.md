Here are the precise, interview-ready definitions for every term on your list. These are structured to give the exact keywords technical interviewers listen for.

### 1. C++ & C Fundamentals

* **Pointers:** Variables that store the direct memory address of another variable.
* **Memory Management:** The process of manually allocating memory on the heap (using `new` in C++ or `malloc` in C) and deallocating it (using `delete` or `free`) to prevent memory leaks.
* **Virtual Functions:** Member functions declared in a base class and redefined (overridden) in a derived class. They enable runtime polymorphism (dynamic dispatch), ensuring the correct function is called for an object, regardless of the pointer type used for it.
* **Polymorphism:** The ability of a function, object, or method to take on multiple forms. (e.g., *Compile-time:* Function overloading; *Run-time:* Method overriding using virtual functions).
* **Inheritance:** A mechanism where a new class (derived class) inherits the properties and behaviors of an existing class (base class), promoting code reusability.
* **Encapsulation:** Bundling data (variables) and the methods that operate on that data into a single unit (a class). It restricts direct access to some of the object's components using access modifiers (private, protected, public).
* **Abstraction:** Hiding complex background implementation details and showing only the essential features of an object to the outside world, often achieved using abstract classes or interfaces.

### 2. React/Next.js

* **Virtual DOM:** A lightweight, in-memory representation of the real DOM. When state changes, React updates the Virtual DOM, compares it to the previous version (a process called "diffing"), and calculates the absolute minimum number of changes needed to update the real browser DOM.
* **useState:** A React Hook that allows functional components to store, track, and update local state variables.
* **useEffect:** A React Hook used to manage side effects in functional components, such as fetching data, manipulating the DOM, or setting up subscriptions. It replaces lifecycle methods like `componentDidMount` and `componentDidUpdate`.
* **SSR (Server-Side Rendering):** A Next.js rendering method where the HTML for a page is generated on the server *every time a user requests it*. It is excellent for dynamic data and SEO.
* **SSG (Static Site Generation):** A Next.js rendering method where the HTML is generated exactly once at *build time*. The same static HTML file is served to every user, making page loads incredibly fast.
* **Context API:** A React feature that allows you to share state globally across the entire component tree without having to manually pass props down through every single level (solving the problem of "prop drilling").

### 3. Node.js/Express

* **Event Loop:** The secret behind Node.js's performance. It is a mechanism that allows Node.js to perform non-blocking I/O operations—despite being single-threaded—by offloading heavy tasks (like reading files or database queries) to the system kernel and executing a callback function when the task finishes.
* **Middleware:** Functions in Express that have access to the request object (`req`), the response object (`res`), and the `next` function in the application’s request-response cycle. They are used to execute code, modify request data (like authentication parsing), or end the request.
* **REST API Principles:** A set of architectural constraints for web services. Key principles include client-server separation, statelessness (the server does not store client session data), standard HTTP methods (GET, POST, PUT, DELETE), and resource-based URLs.

### 4. Databases (SQL/MongoDB)

* **NoSQL vs. SQL:** SQL databases are relational, storing data in highly structured tables with predefined schemas (rows and columns). NoSQL databases (like MongoDB) are non-relational, storing data in flexible, document-based formats (like JSON) where the schema can change on the fly.
* **Indexing:** A data structure technique (often a B-Tree) used to drastically speed up data retrieval operations in a database table, at the cost of slightly slower writes and more storage space.
* **Normalization:** The process of organizing data in a relational database to reduce data redundancy and improve data integrity, usually by dividing large tables into smaller, linked tables using foreign keys.
* **Mongoose Schemas:** A blueprint in Mongoose (an Object Data Modeling library for Node.js) used to define the exact structure, data types, default values, and validation rules for documents within a specific MongoDB collection.

### 5. Coursework Topics (OS & Networking)

* **Concurrency:** The ability of a system to manage multiple tasks making progress at the same time (overlapping their execution, even if they aren't running in the exact same microsecond).
* **Multithreading:** A specific form of concurrency where a single process executes multiple threads (smaller units of execution) simultaneously, sharing the same memory space.
* **Deadlocks:** A critical failure where two or more threads or processes are stuck indefinitely because each is waiting for a resource that the other holds.
* **Race Conditions:** A bug that occurs when multiple threads access and modify shared data simultaneously, and the final output depends on the unpredictable timing of the threads' execution.
* **Mutexes (Mutual Exclusion):** A locking mechanism used in multithreading to ensure that only one thread can access a critical section of code or a shared resource at a time, preventing race conditions.
* **TCP/IP:** The foundational suite of communication protocols for the internet. TCP (Transmission Control Protocol) ensures data is delivered reliably, accurately, and in the correct order.
* **HTTP vs. HTTPS:** HTTP is the standard protocol for transferring data over the web. HTTPS is the secure version, which encrypts the data during transfer using SSL/TLS protocols to prevent hackers from intercepting it.
* **WebSockets:** A communication protocol that provides full-duplex, two-way, continuous communication over a single, long-held TCP connection. Unlike HTTP, which requires a new request for every response, WebSockets allow servers to push real-time data to the client instantly.`