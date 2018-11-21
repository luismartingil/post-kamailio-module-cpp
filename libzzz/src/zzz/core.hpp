/*
 */

#ifndef ZZZ_CORE_HPP
#define ZZZ_CORE_HPP

namespace zzz {

  class core {

  public:
    explicit core(const unsigned int number,
		  const std::string text);
    unsigned int get_number(void);
    unsigned int get_incremented_number(void);
    std::string get_text(void);

  private:
    unsigned int _number;
    std::string _text;

  };

} // core zzz

#endif // ZZZ_CORE_HPP
