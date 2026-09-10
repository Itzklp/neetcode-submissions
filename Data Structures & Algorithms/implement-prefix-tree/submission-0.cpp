class Node {
   public:
    Node* links[26] = {};
    bool isEnd = false;

    Node() {};

    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }

    void put(char ch, Node* node) { links[ch - 'a'] = node; }

    Node* get(char ch) { return links[ch - 'a']; }

    bool getEnd() { return isEnd; }

    void setEnd() { isEnd = true; }
};
class Trie {
   private:
    Node* root;

   public:
    Trie() { root = new Node(); }

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

    bool search(string& s) {
        Node* node = root;

        for (char ch : s) {
            if (!node->containsKey(ch)) {
                return false;
            }

            node = node->get(ch);
        }

        return node->getEnd();
    }

    bool startsWith(string& s) {
        Node* node = root;

        for (char ch : s) {
            if (!node->containsKey(ch)) {
                return false;
            }

            node = node->get(ch);
        }

        return true;
    }
};
class PrefixTree {
   private:
    Trie* t;

   public:
    PrefixTree() { t = new Trie(); }

    void insert(string word) { t->insert(word); }

    bool search(string word) { return t->search(word); }

    bool startsWith(string prefix) { return t->startsWith(prefix); }
};
