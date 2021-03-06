#ifndef __CHECKSIEVE_H__
#define __CHECKSIEVE_H__

#ifndef PLATFORM
#if defined __APPLE__ && defined __MACH__
#define PLATFORM "Darwin"
#endif
#endif

#include <string>
#include "location.hh"

namespace sieve 
{

struct parse_result {
    int status;
    yy::location location;
    std::string error;
    std::string hint;

    void set_error( std::string err ) {
        status = 1;
        error = err;
    }

    void set_error( std::string err, yy::location loc ) {
        status = 1;
        error = err;
        location = loc;
    }
};

struct parse_options {
    parse_options() : string_list_max_length(0) {}
    int string_list_max_length;
};

struct parse_result sieve_parse_file( const char *filename, struct parse_options options );
struct parse_result sieve_parse_string( const char *sieve, struct parse_options options );

const char *version();

} // namespace sieve

#endif
