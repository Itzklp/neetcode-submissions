class Node {
public:
    Node* links[26] = {};
    bool isEnd = false;

    Node() {}

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    bool getEnd() {
        return isEnd;
    }

    void setEnd() {
        isEnd = true;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string& s) {
        Node* node = root;

        for (char ch : s) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }

            node = node->get(ch);
        }

        node->setEnd();
    }

    Node* getRoot() {
        return root;
    }
};

class WordDictionary {
private:
    Trie t;

public:

    bool dfs(Node* node, string& s, int i) {

        if (node == nullptr) {
            return false;
        }

        // IMPORTANT
        if (i == s.size()) {
            return node->getEnd();
        }

        char ch = s[i];

        // Normal character
        if (ch != '.') {

            if (!node->containsKey(ch)) {
                return false;
            }

            return dfs(node->get(ch), s, i + 1);
        }

        // '.': try all 26 possibilities
        for (int j = 0; j < 26; j++) {

            if (node->links[j] != nullptr) {

                if (dfs(node->links[j], s, i + 1)) {
                    return true;
                }
            }
        }

        return false;
    }

    void addWord(string word) {
        t.insert(word);
    }

    bool search(string word) {
        return dfs(t.getRoot(), word, 0);
    }
};