//
//  main.c
//  rMRUBY
//
//  Created by Kanbaru Suruga on 2020/1/2.
//  Copyright © 2020 Kanbaru Suruga. All rights reserved.
//

#include <mruby.h>
#include <mruby/compile.h>
#include "rMRuby.h"

int main( int argc, const char * argv[] ) {

    // insert code here...
    printf( "rMRUBY\n" );

    mrb_state* M = mrb_open();

    mrb_raylib_module_init( M );

    mrb_value v;
    mrbc_context* context = mrbc_context_new( M );

    mrbc_filename( M, context, "main.rb" );

    v = mrb_load_file_cxt( M, fopen( "main.rb", "rb" ), context );

    if ( M->exc ) {

        //mrb_value exc = mrb_obj_value ( M->exc );

        //mrb_value backtrace = mrb_get_backtrace ( M );
        //puts ( mrb_str_to_cstr ( M, mrb_inspect ( M, backtrace ) ) );

        //mrb_value inspect = mrb_inspect ( M, exc );
        //puts ( mrb_str_to_cstr ( M, inspect ) );

        if ( mrb_undef_p ( v ) ) {
            mrb_p( M, mrb_obj_value( M->exc ) );
        }
        else {
            mrb_print_error( M );
        }

        mrbc_context_free( M, context );

        return -1;
    }

    mrbc_context_free( M, context );

    return 0;
}
