/*
 * Copyright ©2022 Dylan Hartono.  All rights reserved.
 */

#ifndef INDEXTABLEREADER_H_
#define INDEXTABLEREADER_H_

#include <string>    // for std::string.
#include <cstdio>    // for (FILE*)

#include "HashTableReader.h"
#include "DocIDTableReader.h"

namespace hw3 {

// An IndexTableReader is a derived class of HashTableReader used to
// read the word --> docIDtable "index" within the index file.
class IndexTableReader : protected HashTableReader {
 public:
  // Construct an IndexTableReader.  Arguments:
  //
  // - f: an open (FILE*) for the underlying index file.  The new
  //   object takes ownership of the (FILE*) and will fclose() it
  //   on destruction.
  //
  // - offset: the file offset of the first byte of the doctable
  IndexTableReader(FILE* f, IndexFileOffset_t offset);

  ~IndexTableReader() { }

  // Lookup a word and get back a DocIDTableReader containing the
  // docID-->positions mapping associated with the docID.
  //
  // Arguments:
  // - word: the word to look for
  //
  // Returns:
  // - a pointer to a DocIDTableReader if the word is found.  The caller
  //   takes ownership of this pointer, and must call delete on it when
  //   done with the object.
  // - `nullptr` if the word is not found.
  DocIDTableReader* LookupWord(const std::string& word) const;

 private:
  // This is here so that the Test_IndexTableReader unit test fixture can
  // access protected member variables of IndexTableReader.  See
  // test_indextablereader.h for details.
  friend class Test_IndexTableReader;

  DISALLOW_COPY_AND_ASSIGN(IndexTableReader);
};

}  // namespace hw3

#endif  // INDEXTABLEREADER_H_