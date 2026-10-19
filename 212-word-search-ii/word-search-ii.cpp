class Solution {
public:

    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        string word;

        TrieNode() {
            isEnd = false;
            word = "";

            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root = new TrieNode();

    // Insert a word into Trie
    void insert(string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->isEnd = true;
        curr->word = word;
    }

    // DFS on board
    void dfs(int r, int c,
             TrieNode* curr,
             vector<vector<char>>& board,
             vector<string>& ans) {

        // Outside board
        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size()) {
            return;
        }

        // Already visited
        if (board[r][c] == '#') {
            return;
        }

        // Current character
        char ch = board[r][c];

        int index = ch - 'a';

        // Character not present in Trie
        if (curr->children[index] == nullptr) {
            return;
        }

        // Move to Trie child
        curr = curr->children[index];

        // Complete word found
        if (curr->isEnd) {
            ans.push_back(curr->word);

            // Avoid adding the same word again
            curr->isEnd = false;
        }

        // Mark visited
        board[r][c] = '#';

        // Down
        dfs(r + 1, c, curr, board, ans);

        // Up
        dfs(r - 1, c, curr, board, ans);

        // Right
        dfs(r, c + 1, curr, board, ans);

        // Left
        dfs(r, c - 1, curr, board, ans);

        // Backtrack
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        // 1. Put all words into Trie
        for (string word : words) {
            insert(word);
        }

        vector<string> ans;

        // 2. Start DFS from every board cell
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                dfs(r, c, root, board, ans);
            }
        }

        return ans;
    }
};