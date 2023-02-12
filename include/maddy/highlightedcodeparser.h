/*
 * This project is licensed under the MIT license. For more information see the
 * LICENSE file.
 */
#pragma once

#include "codeblockparser.h"

namespace maddy
{
  /**
   * HighlightedCodeParser
   *
   * Extends CodeBlockParser with syntax highlightning.
   *
   *
   * @class
   */
  class HighlightedCodeParser : public CodeBlockParser
  {
  public:
    /**
   * ctor
   * 
   * @method
   * @param {std::function<void(std::string&)>} parseLineCallback
   * @param {std::function<std::shared_ptr<BlockParser>(const std::string& line)>} getBlockParserForLineCallback
   */
    HighlightedCodeParser(
      std::function<void(std::string&)> parseLineCallback,
      std::function<std::shared_ptr<BlockParser>(const std::string& line)> getBlockParserForLineCallback
    )
      : CodeBlockParser(parseLineCallback, getBlockParserForLineCallback)
    {}

    void
    parseBlock(std::string& line) override
    {
      std::string codeBlockDecl(line.begin(), line.begin() + 3); //Extract the first three characters from the line.
      //skip line if it doesn't mark the beginning or end of a code block.
      if(codeBlockDecl != "```") 
      {
        line += "\n";
        return;
      }

      if(!this->isStarted)
      {
        std::string language(line.begin() + 3, line.end()); //Extract the language name assuming the line is written as "```<lang-name>"
        if(language.empty()) return CodeBlockParser::parseBlock(line); //If no language is specified, parse as if we're using a plain CodeBlockParser.

        //Else, create a highlighted code with the specified language.
        line = "<pre><code class = \"language-" + language + "\">\n"; //Notice we're using a class for the code tag.
        this->isStarted = true;
        this->isFinished = false;
        return;
      }
      else
      {
        line = "</code></pre>";
        this->isFinished = true;
        this->isStarted = false;
        return;
      }
    }
  };
} // namespace maddy
