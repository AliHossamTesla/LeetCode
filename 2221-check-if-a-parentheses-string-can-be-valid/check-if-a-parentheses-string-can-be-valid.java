class Solution {
    public boolean canBeValid(String s, String locked) {
        int n = s.length();
        if (n % 2 == 1) return false; // Odd-length strings cannot be balanced

        // Check from left to right (treat '(' as open)
        if (!validate(s.toCharArray(), locked.toCharArray(), '(')) {
            return false;
        }

        // Check from right to left (treat ')' as open)
        if (!validateReverse(s.toCharArray(), locked.toCharArray(), ')')) {
            return false;
        }

        return true;
    }

    private boolean validate(char[] s, char[] locked, char openChar) {
        int balance = 0;
        int unlocked = 0;

        for (int i = 0; i < s.length; i++) {
            if (locked[i] == '0') {
                unlocked++; // Unlocked, can be used as either '(' or ')'
            } else {
                if (s[i] == openChar) {
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

    private boolean validateReverse(char[] s, char[] locked, char openChar) {
        int balance = 0;
        int unlocked = 0;

        for (int i = s.length - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                unlocked++; // Unlocked, can be used as either '(' or ')'
            } else {
                if (s[i] == openChar) {
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