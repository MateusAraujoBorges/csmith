#ifndef SVCOMP_EXTENSION_H
#define SVCOMP_EXTENSION_H

#include <vector>
#include <ostream>
#include <string>
#include "AbsExtension.h"
#include "CVQualifiers.h"

class ExtensionValue;

class SvcompExtension : public AbsExtension {
	friend class ExtensionMgr;
public:
	virtual void GenerateValues();

	virtual void Initialize(unsigned int num, vector<ExtensionValue *> &values);

	virtual void OutputInit(std::ostream &out);

	virtual void OutputFirstFunInvocation(std::ostream &out, FunctionInvocation *invoke);

	virtual void OutputHeader(std::ostream &out);

	virtual void OutputTail(std::ostream &out);

	virtual std::vector<ExtensionValue *> &get_values() { return values_; }

private:

	static std::string input_base_name_;

	void output_symbolics(std::ostream &out);

	std::vector<ExtensionValue*> values_;

	SvcompExtension();

	~SvcompExtension();
};

#endif // SVCOMP_EXTENSION_H
