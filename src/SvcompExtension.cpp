// -*- mode: C++ -*-
//
// Copyright (c) 2008, 2009, 2010, 2011, 2015, 2017 The University of Utah
// All rights reserved.
//
// This file is part of `csmith', a random generator of C programs.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in the
//     documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sstream>
#include <cassert>
#include "SvcompExtension.h"
#include "Type.h"
#include "ExtensionValue.h"

using namespace std;

std::string SvcompExtension::input_base_name_ = "input";

SvcompExtension::SvcompExtension()
{

}

SvcompExtension::~SvcompExtension()
{
	values_.clear();
}

void
SvcompExtension::GenerateValues()
{

}

//Only integers for svcomp
void
SvcompExtension::Initialize(unsigned int num, vector<ExtensionValue *> &values)
{
	for (unsigned int i = 0; i < num; i++) {
        const Type* type = &Type::get_simple_type(eInt);
		std::ostringstream s;
		s << SvcompExtension::input_base_name_ << i;
		ExtensionValue *sv = new ExtensionValue(type, s.str());
		assert(sv);
		values.push_back(sv);
	}
}

void
SvcompExtension::output_symbolics(ostream &out)
{
	std::vector<ExtensionValue*>::iterator i;
	for (i = values_.begin(); i != values_.end(); ++i) {
		assert(*i);
		out << AbsExtension::tab_;
		out << (*i)->get_name() << " = __VERIFIER_nondet_int();" << endl;
	}
}

void
SvcompExtension::OutputInit(std::ostream &out)
{
	out << "int main(void)" << endl;
	out << "{" << endl;
	AbsExtension::default_output_definitions(out, values_, false);
	output_symbolics(out);
}

void
SvcompExtension::OutputHeader(std::ostream &out)
{
  out << "#ifdef RANDOM_INPUT" << endl;
  out << "#include <stdlib.h>" << endl;
  out << "#include <stdio.h>" << endl;
  out << "" << endl;
  out << "int __VERIFIER_nondet_int(void) {" << endl;
  out << "  FILE *f_random;" << endl;
  out << "  f_random = fopen(\"/dev/urandom\",\"r\");" << endl;
  out << "  int randval;" << endl;
  out << "  fread(&randval, sizeof(randval), 1, f_random);" << endl;
  out << "  fclose(f_random);" << endl;
  out << "  printf(\"[csmith] read %d from /dev/urandom\\n\",randval);" << endl;
  out << "  return randval;" << endl;
  out << "}" << endl;
  out << "void __VERIFIER_error(void) {" << endl;
  out << "  printf(\"VERIFIER_ERRROR reached!\\n\");" << endl;
  out << "  exit(42);" << endl;
  out << "}" << endl;
  out << "#else" << endl;
  out << "extern void __VERIFIER_error(void);" << endl;
  out << "extern int __VERIFIER_nondet_int(void);" << endl;
  out << "extern void exit(int);" << endl;
  out << "#endif" << endl;
  out << "int __VERIFIER_error_proxy() {" << endl;
  out << "  __VERIFIER_error();" << endl;
  out << "  return -1;" << endl;
  out << "}" << endl;
}

void
SvcompExtension::OutputTail(std::ostream &out)
{
	out << AbsExtension::tab_ << "return 0;" << endl;
}

void
SvcompExtension::OutputFirstFunInvocation(std::ostream &out, FunctionInvocation *invoke)
{
	AbsExtension::OutputFirstFunInvocation(out, invoke);
}
