#include <stdio.h>
#include <stdlib.h>

struct item
{
    int ID;
    char name[50];
    float price;
    int quantity;
};

struct item * readGroceryList (int count)
{
    struct item * gItems = (struct item *) malloc(sizeof(struct item) * count);
    if (gItems == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    int uniqueNum = 1;
    int i;
    for (i = 0; i<count; i++)
    {
        gItems[i].ID = uniqueNum++;
        printf("\nEnter the details for item %d: \n", i+1);
        printf("Name: ");
        scanf("%s", gItems[i].name);
        printf("Price: ");
        scanf("%f", &gItems[i].price);
        printf("Quantity: ");
        scanf("%d", &gItems[i].quantity);
    }

    return gItems;
};

void printGroceryList(struct item * gItems, int count)
{
    printf("\n");
    int i;
    for (i = 0; i<count; i++)
    {
        printf("Item ID: %d\t", gItems[i].ID);
        printf("Name: %s\t", gItems[i].name);
        printf("Price: %f\t", gItems[i].price);
        printf("Quantity: %d\n", gItems[i].quantity);
    }
}

struct item findItem(int qVal, struct item * gItems, int count)
{
    int i = 0;
    int index = -1;
    while (i<count)
    {
        if (gItems[i].quantity == qVal)
        {
            index = i;
            return gItems[index];
        }
        i++;
    }

    struct item emptyItem;
    emptyItem.ID = -1;
    return emptyItem;
}

struct item findMaxPriceItem(struct item * gItems, int count)
{
    int i = 0;
    int max_index = -1;
    float max_price = -1.0f;
    for (i = 0; i<count; i++)
    {
        if (gItems[i].price > max_price)
        {
            max_price = gItems[i].price;
            max_index = i;
        }
        else
            continue;
    }
    return gItems[max_index];
}

int main()
{
    int num_q;
    printf("Enter number of unique grocery items in the store: ");
    scanf("%d", &num_q);

    struct item *gItems_main = readGroceryList(num_q);

    printGroceryList(gItems_main, num_q);

    int qVal;
    printf("\nEnter quantity of the item you wish to find: ");
    scanf("%d", &qVal);
    struct item fitem = findItem(qVal, gItems_main, num_q);

    if (fitem.ID == -1)
    {
        printf("Item not found.\n");
    }
    else
    {
        printf("The item found with quantity %d is: \n", qVal);
        printf("ID: %d\t", fitem.ID);
        printf("Name: %s\t", fitem.name);
        printf("Price: %f\t", fitem.price);
    }

    struct item maxItem = findMaxPriceItem(gItems_main, num_q);
    printf("\nThe item with maximum price is :\n");
    printf("ID: %d\t", maxItem.ID);
    printf("Name: %s\t", maxItem.name);
    printf("Price: %f\t", maxItem.price);
    printf("Quantity: %d\t", maxItem.quantity);

    free(gItems_main);
    return 0;
}