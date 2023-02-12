/*
 * This project is licensed under the MIT license. For more information see the
 * LICENSE file.
 */
#pragma once

// -----------------------------------------------------------------------------

namespace maddy {

// -----------------------------------------------------------------------------

/**
 * ParserConfig
 *
 * @class
 */
struct ParserConfig
{
  bool isEmphasizedParserEnabled;
  bool isHTMLWrappedInParagraph;
  bool isSyntaxHighlightningEnabled;
  //If true, settings from htmlPageSettings will be used.
  bool generateEntireHTMLDocument; 

  struct HTMLSettings
  {
    std::string Language;
    std::string Title;
  } htmlPageSettings;

  ParserConfig()
    : isEmphasizedParserEnabled(true)
    , isHTMLWrappedInParagraph(true)
    , isSyntaxHighlightningEnabled(false)
    , generateEntireHTMLDocument(false)
    , htmlPageSettings({"en","Untitled"})
  {}
}; // class ParserConfig

// -----------------------------------------------------------------------------

} // namespace maddy
