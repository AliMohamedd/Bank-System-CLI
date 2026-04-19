# 🏦 Bank-System-CLI

**Bank-System-CLI** is a C++ command-line banking system that simulates real-world banking operations with persistent storage and basic security features.
The project uses a **text file-based database** with simple encryption to manage users, clients, transactions, and system logs.

---

## 📦 Project Overview

### 🏦 Bank System (CLI)

A full-featured console-based banking system that handles user authentication, client management, and financial operations.

---

## 🔐 Key Features

### 👤 User Authentication

* Secure login system
* Password encryption before storage
* Registration system for new users
* Login tracking system (audit logs)

---

### 👥 Client Management

* Add new clients
* Update client information
* View client details
* Store client data persistently in text files

---

### 💰 Banking Operations

* Deposit funds
* Withdraw funds
* Check account balances
* Transfer money between accounts

---

### 📄 Data Persistence (Text File Database)

All system data is stored using structured text files, including:

* Users data
* Clients data
* Login records
* Transfer logs

---

### 📊 Logging System

* Records all money transfers (`TransferLog`)
* Tracks user login attempts (`LoginRegister`)
* Maintains system activity history for auditing

---

### 🔒 Security Features

* Basic password encryption before saving to files
* Protected access through authentication and authorization
* Separated data layers for users and clients

---

## 🎯 Challenges 

The most to mention:

* How to make permission checking in O(1) instead of O(n)

---

## 🚀 Getting Started

### Prerequisites

* C++ compiler (e.g., `g++`)
* Windows / Linux / macOS
* Any IDE (Visual Studio, VS Code, etc.)

---

### Running the Project

#### ▶️ Compile & Run

```bash id="p2n7wx"
g++ main.cpp -o BankSystem
./BankSystem
```

> Make sure all `.txt` database files are in the same directory as the executable.

---

## 📁 Repository Structure

```id="a8v4dk"
Bank-System-CLI/
│
├── Bank-System-CLI/
│   ├── Include/
│   ├── Users.txt
│   ├── Clients.txt
│   ├── TransferLog.txt
│   └── LoginRegister.txt
└── Bank-System-CLI.sln
```

---

## 🎯 Purpose

This project is designed to:

* Simulate a real banking system using CLI
* Practice **file handling in C++**
* Implement basic **data persistence without databases**
* Learn simple **encryption techniques**
* Improve system design and logic-building skills

---

## 📄 License

This project is open-source and available under the MIT License.
