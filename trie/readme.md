# TRIE

## Structure of Trie Node

```sh
struct TrieNode {
    TrieNode *child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i=0; i<26; i++) {
            child[i] = NULL;
        }
    }
};
```

### An empty trie is represented with its root where it's isEnd value is false and all it's children are null.

## Insert Function in Trie

```sh
TrieNode *root;

void insert(string &key) {
    TrieNode *curr = root;
    for(int i=0; i<key.length(); i++) {
        int index = key[i]-'a';
        if(curr->child[index] == NULL) {
            curr->child[index] = new TrieNode();
        }
        curr = curr->child[index];
    }
    curr->isEnd = true;
}
```

## Search Function in Trie

```sh
TrieNode *root;

bool search(string &key) {
    Trie *curr = root;
    for(int i=0; i<key.length(); i++) {
        int index = key[i]-'a';
        if(curr->child[index] == NULL) {
            return false;
        } 
        curr = curr->child[index];
    }
    return curr->isEnd;
}
```

## Uses of Trie Data Structure

1. Dictionary
   - Search:- O(n)
   - Store
   - Remove
2. Finding prefixes
3. Ordered, structured and clean DS
4. Count Distinct Rows in Binary Matrix