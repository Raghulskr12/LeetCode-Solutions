class Solution {
    public boolean wordPattern(String pattern, String s) {

        HashMap<Character, String> freq = new HashMap<>();

        String[] temp = s.split(" ");

        if (pattern.length() != temp.length)
            return false;

        for (int i = 0; i < temp.length; i++) {

            char ch = pattern.charAt(i);
            String str = temp[i];

            if (freq.containsKey(ch)) {

                if (!freq.get(ch).equals(str))
                    return false;

            } else {

                if (freq.containsValue(str))
                    return false;

                freq.put(ch, str);
            }
        }

        return true;
    }
}
