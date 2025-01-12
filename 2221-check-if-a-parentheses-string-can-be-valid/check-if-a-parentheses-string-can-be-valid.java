class Solution {
    public boolean canBeValid(String s, String locked) {
        int n = s.length();
        if (n % 2 == 1) return false; // Odd-length strings cannot be balanced

        // Check from left to right (treat '(' as open)
        if (!validate(s, locked, '(')) {
            return false;
        }

        // Check from right to left (treat ')' as open)
        if (!validate(new StringBuilder(s).reverse().toString(), 
                      new StringBuilder(locked).reverse().toString(), ')')) {
            return false;
        }

        return true;
    }

    private boolean validate(String s, String locked, char openChar) {
        int balance = 0;
        int unlocked = 0;

        for (int i = 0; i < s.length(); i++) {
            if (locked.charAt(i) == '0') {
                unlocked++; // Unlocked, can be used as either '(' or ')'
            } else {
                if (s.charAt(i) == openChar) {
                    balance++; // Increment balance for openChar
                } else {
                    balance--; // Decrement balance for closeChar
                }
            }

            // If balance + unlocked < 0, it means we have more closeChars than openChars
            // and we cannot fix it with unlocked characters
            if (balance + unlocked < 0) {
                return false;
            }
        }

        return true;
    }
}