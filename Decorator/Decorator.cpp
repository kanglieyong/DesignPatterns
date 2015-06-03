#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Paragraph
{
public:
  Paragraph(const string& inInitialText)
    : mText(inInitialText) {}

  virtual string getHTML() const { return mText; }

protected:
  string mText;
};

class BoldParagraph : public Paragraph
{
public:
  BoldParagraph(const Paragraph& inParagraph)
    : Paragraph(""),
      mWrapped(inParagraph) {}

  virtual string getHTML() const {
    return "<B>" + mWrapped.getHTML() + "</B>";
  }
  
protected:
  const Paragraph& mWrapped;
};

class ItalicParagraph : public Paragraph
{
public:
  ItalicParagraph(const Paragraph& inParagraph)
    : Paragraph(""),
      mWrapped(inParagraph) {}

  virtual string getHTML() const {
    return "<I>" + mWrapped.getHTML() + "</I>";
  }

protected:
  const Paragraph& mWrapped;
};

int main(void)
{
  Paragraph p("A party? For me? Thanks!");

  cout << BoldParagraph(p).getHTML() << endl;
  cout << BoldParagraph(BoldParagraph(p)).getHTML() << endl;
  cout << ItalicParagraph(BoldParagraph(p)).getHTML() << endl;

  return 0;
}
