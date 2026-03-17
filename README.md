# Flash Sale Tool

**Description:**  
A C program that manages product flash sales by storing product codes, names, original prices, and flash sale prices in a CSV file. The program automatically calculates discounts, allows listing, updates existing products, and prevents duplicates.  

---

## Features
- Add new products with flash sale information
- Prevent empty inputs
- List all products in a table with discount and description
- Check for duplicate product codes and allow updates
- Automated description: `! ! ! CLEARANCE SALES -> Now [FlashPrice] ([OriginalPrice]) Grab yours before stock runs out!`
- Fully stored in `data/products.csv`
- Easy to compile and clean with Makefile

---

## Project Structure

```text
flash-sale-tool/
│
├─ src/                   <-- Source folder
│   └─ main.c             <-- Main C program
├─ obj/                   <-- Object folder
│   └─ main.o             <-- Object file
├─ bin/                   <-- Executable folder
│   └─ *tool.exe          <-- Executable program
├─ env/                   <-- Script folder
│   ├─ git_setup.bat      <-- Git config script (Linux/Bash)
│   └─ git_setup.sh       <-- Git config batch file (CMD)
├─ data/                  <-- CSV storage folder
│   ├─ products.csv       <-- Main product data file
│   └─ temp.csv           <-- Temporary file for updates
├─ Makefile               <-- Compile & clean automation
├─ README.md              <-- Documentation/manual
├─ LICENSE                <-- Project MIT license
└─ .gitignore             <--Git ignore file

```
---

## Environment Setup

- Git Config Setup
1. Check Git installed
2. Ask for username
3. Ask for email
4. Configure Git