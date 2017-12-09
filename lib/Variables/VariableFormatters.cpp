#include <Arduino.h>
#include <VariableFormatters.h>

std::shared_ptr<const VariableFormatter> VariableFormatter::buildFormatter(const JsonObject& args) {
  String formatter = args["formatter"];

  if (formatter.equalsIgnoreCase("time")) {
    return TimeVariableFormatter::build(args["args"]);
  } else if (formatter.equalsIgnoreCase("cases")) {
    return std::shared_ptr<const VariableFormatter>(new CasesVariableFormatter(args.get<const JsonObject&>("args")));
  } else {
    return std::shared_ptr<const VariableFormatter>(new IdentityVariableFormatter());
  }
}

String IdentityVariableFormatter::format(const String& value) const {
  return value;
}
