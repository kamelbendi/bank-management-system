#include "normalaccount.h"

// Static value initialization should not be in the header file, since they cant be initialized inside the class itself.
// Cause each time we include the header it will try to reinitialize it
// which we dont want that kind of behaviour, since we are trying to keep this constant increasing with the number of accounts created
int NormalAccount::account_count = 1;
