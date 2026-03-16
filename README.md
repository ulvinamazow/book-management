# 📚 Book Management System

A simple C++ console application for managing books. You can add, list, search, and delete books. All data is stored in a `books.txt` file and automatically loaded when the program starts.

## 🚀 Features

- ✅ **Add Book** – Enter ID, title, author, and publication year. ID must be unique.
- 📖 **List Books** – Display all books in the library.
- 🔍 **Search Book** – Search for books by title.
- ❌ **Delete Book** – Remove a book by its ID.
- 💾 **Persistent Storage** – All books are saved in `books.txt` and persist between program sessions.

## 🛠 Technologies

- **Language:** C++
- **Libraries:** Standard libraries (`iostream`, `fstream`, `sstream`, `vector`, `string`)
- **Data Storage:** Text file (`.txt`)

## 📦 Installation & Usage

1. **Clone the repository:**
   ```bash
   git clone https://github.com/ulvinamazow/book-management.git
   cd book-management

Compile the code:

bash
g++ -o book main.cpp
Run the program:

bash
./book
Note: On Windows, run book.exe.

📁 File Structure
text
📂 book-management
├── 📄 main.cpp          # Main source code
├── 📄 books.txt         # Data storage file (auto-generated)
├── 📄 README.md         # Project documentation
📝 How to Use
When you run the program, a menu will appear.

Choose an operation by entering a number (1-5).

When adding a book, the ID must be unique.

Search is case-sensitive and matches the exact title.

📄 books.txt File Format
Each book is stored on a single line, with fields separated by commas:
