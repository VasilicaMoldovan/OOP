#include <stdio.h>
#include "Console.h"

Substance* uiAddOrUpdateIngredient(char command[], char* strtokPointer, int catalogingNumber, char state[], char intendedUse[], int potency) {
	strcpy(command, strtokPointer);
	strtokPointer = strtok(NULL, " ");
	catalogingNumber = atoi(strtokPointer);
	strtokPointer = strtok(NULL, " ");
	strcpy(state, strtokPointer);
	strtokPointer = strtok(NULL, " ");
	strcpy(intendedUse, strtokPointer);
	strtokPointer = strtok(NULL, " ");
	potency = atoi(strtokPointer);
	Substance* newSubstance = createSubstance(catalogingNumber, state, intendedUse, potency);
}

void run() {
	char command[250];
	int exitCondition = 0;
	int catalogingNumber = 0, potency = 0;
	char state[64], intendedUse[100];
	Substance* newSubstance;
	SubstancesController* controllerList;
	controllerList = createController();
	char errors[200], listToBePrinted[10000];
	int numberOfUndos = -1;

	while ( exitCondition == 0) {
		fgets(command, 200, stdin);
		strcpy(errors, "");
		char *strtokPointer = strtok(&command, " \n");
		if (strcmp(strtokPointer, "add") == 0 || strcmp(strtokPointer, "update") == 0) {
			newSubstance = uiAddOrUpdateIngredient(command, strtokPointer, catalogingNumber, state, intendedUse, potency);
			
			if (strcmp(command, "add") == 0) {
				addNewIngredient(errors, newSubstance, controllerList);
				if(strcmp(errors, "") != 0)
					printf("%s\n", errors);
				numberOfUndos++;
			}
			else {
				updateIngredient(errors, newSubstance, controllerList);
				if (strcmp(errors, "") != 0)
					printf("%s\n", errors);
				numberOfUndos++;
			}
			
		}
		else {
			if (strcmp(strtokPointer, "delete") == 0) {
				strtokPointer = strtok(NULL, " ");
				catalogingNumber = atoi(strtokPointer);
				newSubstance = createSubstance(catalogingNumber, "", "", 0);
				deleteIngredient(errors, newSubstance, controllerList);
				if (strcmp(errors, "") != 0)
					printf("%s\n", errors);
				numberOfUndos++;
			}
			else {
				if (strcmp(strtokPointer, "list") == 0) {
					strtokPointer = strtok(NULL, " \n");
					if (strtokPointer == NULL) {
						listIngredients(listToBePrinted, controllerList);
						printf("%s", listToBePrinted);
					}
					else {
						if (isalpha(strtokPointer[0]) != 0) {
							strcpy(intendedUse, strtokPointer);
							strtokPointer = strtok(NULL, " \n");
							listFilteredList(listToBePrinted, intendedUse, controllerList, strtokPointer);
							printf("%s", listToBePrinted);
						}
						else {
							potency = atoi(strtokPointer);
							strtokPointer = strtok(NULL, " \n");
							listSortedVector(listToBePrinted, potency, controllerList, strtokPointer);
							printf("%s", listToBePrinted);
						}
					}
				}
				else {
					if (strcmp(strtokPointer, "undo") == 0) {
						strtokPointer = strtok(NULL, " \n");
						if (strcmp(strtokPointer, "1") == 0) {
							
							//secondUndo(errors, controllerList, numberOfUndos);
							numberOfUndos--;
						}
						else 
							undoOperation(errors, controllerList);
						if (strcmp(errors, "") != 0)
							printf("%s\n", errors);
					}
					else {
						if (strcmp(strtokPointer, "redo") == 0) {
							strtokPointer = strtok(NULL, " \n");
							if (strcmp(strtokPointer, "1") == 0) {
								//secondRedo(errors, controllerList, numberOfUndos);
								numberOfUndos++;
							}
							else
								redoOperation(errors, controllerList);
							if (strcmp(errors, "") != 0)
								printf("%s\n", errors);
						}
						else {
							if (strcmp(strtokPointer, "exit") == 0)
								exitCondition = 1;
							else
							{
								printf("The given command is invalid!\n");
								exitCondition = 1;
								deallocateController(controllerList);
							}
						}
					}
				}
			}
		}
	}
}