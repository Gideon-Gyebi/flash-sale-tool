# Flash Sale Tool

**Description:**  
A C program that manages product flash sales by storing product codes, names, original prices, and flash sale prices in a CSV file. The program automatically calculates discounts, allows listing, updates existing products, and prevents duplicates.  

---

## Features
- Add new products with flash sale information
- Prevent empty inputs
- List all products in a table with discount and description
- Check for duplicate product codes and allow updates
- Automated description: `Flash Sale only: [FlashPrice] ([OriginalPrice]) – Get yours now before stock runs out`
- Fully stored in `data/products.csv`
- Easy to compile and clean with Makefile

---

## Project Structure

```text
flash-sale-tool/
│
├─ main.c                 <-- Main C program
├─ Makefile               <-- Compile & clean automation
├─ README.md              <-- This documentation
└─ data/                  <-- CSV storage folder
    ├─ products.csv       <-- Main product data file
    └─ temp.csv           <-- Temporary file for updates

---

## Environment Setup

- Git Setup
1. Check Git installed
2. Ask for username
3. Ask for email
4. Configure Git