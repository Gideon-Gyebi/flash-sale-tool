#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 Flash Sale CSV Tool
 ------------------
 Stores product info in CSV with features:
 - Prevent empty inputs
 - List products
 - Prevent duplicate codes
 - Update existing products
 - Calculate discount
*/

#define CSV_FILE "data/products.csv"
#define TEMP_FILE "data/temp.csv"

// List all products in a table format
void listProducts() {
    FILE *file = fopen(CSV_FILE, "r");
    if (!file) { printf("No products found.\n"); return; }

    char line[300]; int lineCount=0;
    printf("\nCurrent Products:\n");
    printf("Code   Name                 Original   Flash   Discount   Description\n");
    printf("---------------------------------------------------------------\n");

    while (fgets(line, sizeof(line), file)) {
        if (lineCount++ == 0) continue; // skip header
        char code[50], name[100], desc[150]; float orig, flash;
        sscanf(line, "%[^,],%[^,],%f,%f,%[^\n]", code, name, &orig, &flash, desc);
        float discount = ((orig-flash)/orig)*100;
        printf("%-6s %-20s %-8.2f %-6.2f %-3.0f%%   %s\n", code, name, orig, flash, discount, desc);
    }
    fclose(file); printf("\n");
}

// Check if product exists
int productExists(char code[]) {
    FILE *file = fopen(CSV_FILE, "r"); if(!file) return 0;
    char line[300];
    while(fgets(line,sizeof(line),file)){
        char existingCode[50]; sscanf(line,"%[^,]",existingCode);
        if(strcmp(existingCode, code)==0){ fclose(file); return 1; }
    }
    fclose(file); return 0;
}

// Update product line in CSV
void updateProduct(char code[], char name[], float orig, float flash){
    FILE *file = fopen(CSV_FILE,"r"); FILE *temp=fopen(TEMP_FILE,"w");
    if(!file||!temp){printf("Error opening files.\n"); return;}
    char line[300]; int lineCount=0;
    while(fgets(line,sizeof(line),file)){
        if(lineCount++==0){fputs(line,temp); continue;}
        char existingCode[50]; sscanf(line,"%[^,]",existingCode);
        if(strcmp(existingCode, code)==0){
            float discount=((orig-flash)/orig)*100;
            fprintf(temp,"%s,%s,%.2f,%.2f,Flash Sale: %s now %.2f instead of %.2f (%.0f%% off)\n",
                    code,name,orig,flash,name,flash,orig,discount);
        } else { fputs(line,temp); }
    }
    fclose(file); fclose(temp);
    remove(CSV_FILE); rename(TEMP_FILE,CSV_FILE);
    printf("Product updated successfully!\n");
}

int main(){
    char productCode[50], productName[100], inputBuffer[100];
    float originalPrice, flashPrice;

    // Ensure CSV exists & add header
    FILE *file = fopen(CSV_FILE,"a+");
    if(!file){printf("Error opening CSV.\n"); return 1;}
    fseek(file,0,SEEK_END); if(ftell(file)==0){
        fprintf(file,"ProductCode,ProductName,OriginalPrice,FlashPrice,Description\n");
    } fclose(file);

    while(1){
        printf("\nType 'exit' to quit or 'list' to view products.\n");
        // ----------------- PRODUCT CODE -----------------
        do{
            printf("Product Code: "); fgets(productCode,sizeof(productCode),stdin);
            productCode[strcspn(productCode,"\n")]=0;
        }while(strlen(productCode)==0);

        if(strcmp(productCode,"exit")==0) break;
        if(strcmp(productCode,"list")==0){ listProducts(); continue; }

        // ----------------- DUPLICATE CHECK -----------------
        if(productExists(productCode)){
            char choice[10]; printf("Product exists. Update it? (Y/N): ");
            fgets(choice,sizeof(choice),stdin); choice[strcspn(choice,"\n")]=0;
            if(strcmp(choice,"N")==0||strcmp(choice,"n")==0) continue;
        }

        // ----------------- PRODUCT NAME -----------------
        do{ printf("Product Name: "); fgets(productName,sizeof(productName),stdin);
            productName[strcspn(productName,"\n")]=0;
        }while(strlen(productName)==0);

        // ----------------- ORIGINAL PRICE -----------------
        do{ printf("Original Price: "); fgets(inputBuffer,sizeof(inputBuffer),stdin);
        }while(sscanf(inputBuffer,"%f",&originalPrice)!=1);

        // ----------------- FLASH PRICE -----------------
        do{ printf("Flash Sale Price: "); fgets(inputBuffer,sizeof(inputBuffer),stdin);
        }while(sscanf(inputBuffer,"%f",&flashPrice)!=1);

        // ----------------- SAVE OR UPDATE -----------------
        if(productExists(productCode)){
            updateProduct(productCode, productName, originalPrice, flashPrice);
        } else {
            file=fopen(CSV_FILE,"a");
            float discount=((originalPrice-flashPrice)/originalPrice)*100;
            fprintf(file,"%s,%s,%.2f,%.2f,Flash Sale: %s now %.2f instead of %.2f (%.0f%% off)\n",
                    productCode,productName,originalPrice,flashPrice,productName,flashPrice,originalPrice,discount);
            fclose(file); printf("Product saved successfully!\n");
        }
    }
    printf("\nProgram closed.\n"); return 0;
}