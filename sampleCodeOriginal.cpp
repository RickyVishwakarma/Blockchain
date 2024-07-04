#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <crypto++/sha.h>
#include <crypto++/hex.h>

using namespace std;
using namespace CryptoPP;

// Simplified hash calculation
string calculateHash(const string& data, const string& prev_hash) {
  SHA256 hash;
  string toHash = data + prev_hash;

  byte digest[SHA256::DIGESTSIZE];
  hash.CalculateDigest(digest, (const byte*)toHash.c_str(), toHash.length());

  stringstream ss;
  for (int i = 0; i < SHA256::DIGESTSIZE; ++i) {
    ss << hex << setw(2) << setfill('0') << (int)digest[i];
  }
  return ss.str();
}

class Block {
public:
  // Additional timestamp field
  long long timestamp;

  Block(const string& data, const string& prev_hash)
    : data(data), prev_hash(prev_hash), timestamp(chrono::system_clock::now().time_since_epoch().count()) {
      hash = calculateHash(data, prev_hash); 
  }

  string getData() const { return data; }
  string getHash() const { return hash; }
  string getPrevHash() const { return prev_hash; }
  long long getTimestamp() const { return timestamp; }

private:
  string data;
  string hash;
  string prev_hash;
};

class MyBlockchain {
public:
  MyBlockchain() {
    Block genesis("Genesis Block", "0"); // Initial genesis block
    chain.push_back(genesis);
  }

  // Simplified proof-of-work (not secure)
  string proofOfWork(const string& input) {
    string proof = "";
    while (!proof.startsWith("000")) { // Mine for leading zeros (highly simplified)
      proof += to_string(rand());
    }
    return proof;
  }

  void addBlock(const string& data) {
    string prev_hash = chain.back().getHash();
    string proof = proofOfWork(data + prev_hash); // Simplified PoW
    chain.push_back(Block(data, prev_hash));
  }

  bool isChainValid() const {
    int chainSize = chain.size();
    for (int i = 1; i < chainSize; ++i) {
      Block currentBlock = chain[i];
      Block prevBlock = chain[i - 1];

      if (currentBlock.getHash() != calculateHash(currentBlock.getData(), currentBlock.getPrevHash())) {
        return false;
      }

      if (currentBlock.getPrevHash() != prevBlock.getHash()) {
        return false;
      }
    }
    return true;
  }

  void printChain() const {
    for (const Block& block : chain) {
      cout << "Data: " << block.getData() << endl;
      cout << "Hash: " << block.getHash() << endl;
      cout << "Prev Hash: " << block.getPrevHash() << endl;
      cout << "Timestamp: " << block.getTimestamp() << endl << endl;
    }
  }

private:
  vector<Block> chain;
};

int main() {
  MyBlockchain blch;

  blch.addBlock("Block 1");
  blch.addBlock("Block 2");

  cout << "Is chain valid? " << (blch.isChainValid() ? "Yes" : "No") << endl << endl;

  blch.printChain();

  return 0;
}