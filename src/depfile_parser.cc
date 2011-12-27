/* Generated by re2c 0.13.5 */
// Copyright 2011 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "depfile_parser.h"

// A note on backslashes in Makefiles, from reading the docs:
// Backslash-newline is the line continuation character.
// Backslash-# escapes a # (otherwise meaningful as a comment start).
// Backslash-% escapes a % (otherwise meaningful as a special).
// Finally, quoting the GNU manual, "Backslashes that are not in danger
// of quoting ‘%’ characters go unmolested."
// How do you end a line with a backslash?  The netbsd Make docs suggest
// reading the result of a shell command echoing a backslash!
//
// Rather than implement the above, we do the simpler thing here.
// If anyone actually has depfiles that rely on the more complicated
// behavior we can adjust this.
bool DepfileParser::Parse(const string& content, string* err) {
  const char* p = content.data();
  const char* end = content.data() + content.size();
  for (;;) {
    const char* start = p;
    char yych;
    
    {
      static const unsigned char yybm[] = {
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0, 128,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
        128,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,  64,  64,  64,  64,  64, 
         64,  64,  64,  64,  64,  64,  64,  64, 
         64,  64,  64,   0,   0,   0,   0,   0, 
          0,  64,  64,  64,  64,  64,  64,  64, 
         64,  64,  64,  64,  64,  64,  64,  64, 
         64,  64,  64,  64,  64,  64,  64,  64, 
         64,  64,  64,   0,  64,   0,   0,  64, 
          0,  64,  64,  64,  64,  64,  64,  64, 
         64,  64,  64,  64,  64,  64,  64,  64, 
         64,  64,  64,  64,  64,  64,  64,  64, 
         64,  64,  64,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
          0,   0,   0,   0,   0,   0,   0,   0, 
      };

      if ((end - p) < 2) break;
      yych = *p;
      if (yych <= '@') {
        if (yych <= 0x1F) {
          if (yych == '\n') goto yy4;
          goto yy7;
        } else {
          if (yych <= ' ') goto yy4;
          if (yych <= '*') goto yy7;
          if (yych <= ':') goto yy6;
          goto yy7;
        }
      } else {
        if (yych <= '^') {
          if (yych <= 'Z') goto yy6;
          if (yych != '\\') goto yy7;
        } else {
          if (yych == '`') goto yy7;
          if (yych <= 'z') goto yy6;
          goto yy7;
        }
      }
      ++p;
      if ((yych = *p) == '\n') goto yy13;
      goto yy10;
yy3:
      {
      // Got a filename.
      int len = p - start;;
      if (start[len - 1] == ':')
        len--;  // Strip off trailing colon, if any.

      if (len == 0)
        continue;  // Drop isolated colons.

      if (!out_.str_) {
        out_ = StringPiece(start, len);
      } else {
        ins_.push_back(StringPiece(start, len));
      }
      continue;
    }
yy4:
      ++p;
      yych = *p;
      goto yy12;
yy5:
      { continue; }
yy6:
      yych = *++p;
      goto yy10;
yy7:
      ++p;
      {
      *err = "BUG: depfile lexer encountered unknown state";
      return false;
    }
yy9:
      ++p;
      if (end <= p) break;
      yych = *p;
yy10:
      if (yybm[0+yych] & 64) {
        goto yy9;
      }
      goto yy3;
yy11:
      ++p;
      if (end <= p) break;
      yych = *p;
yy12:
      if (yybm[0+yych] & 128) {
        goto yy11;
      }
      goto yy5;
yy13:
      ++p;
      { continue; }
    }

  }
  return true;
}
