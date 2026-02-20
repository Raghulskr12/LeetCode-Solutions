class Solution {

    public boolean isPalindrome(String a) {
        int i = 0, j = a.length() - 1;

        while (i < j) {
            if (a.charAt(i) != a.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }

    public void dfs(String s, int index,
                    List<List<String>> ans,
                    List<String> temp) {

        // ✅ base condition
        if (index == s.length()) {
            ans.add(new ArrayList<>(temp));
            return;
        }

        // explore partitions
        for (int i = index; i < s.length(); i++) {

            String sub = s.substring(index, i + 1);

            if (isPalindrome(sub)) {
                temp.add(sub);

                dfs(s, i + 1, ans, temp);

                temp.remove(temp.size() - 1); // backtrack
            }
        }
    }

    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        dfs(s, 0, ans, new ArrayList<>());
        return ans;
    }
}