/* Provide feedback to the grammar about failed queries to weed out
   unsupported productions. */

#ifndef IMPEDANCE_HH
#define IMPEDANCE_HH

#include <typeinfo>
#include <map>
#include "prod.hh"
#include "log.hh"

struct impedance_visitor : prod_visitor {
  std::map<const char*, long> &_occured;
  std::map<const char*, bool> found;
  virtual void visit(struct prod *p);
  impedance_visitor(std::map<const char*, long> &occured);
  virtual ~impedance_visitor();
};

struct impedance_feedback : logger {
  virtual void executed(prod &query);
  virtual void error(prod &query, const pqxx::failure &e);
  impedance_feedback() { }
};

namespace impedance {
  bool matched(std::type_info &id);
  void report();
}

#endif
