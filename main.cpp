/* 
 * File:   main.cpp
 * Author: thomas
 *
 * Created on November 19, 2012, 5:23 PM
 */

#include <stdio.h>
#include <string.h>
#include <mongoose.h>
#include "CGAL_Binding_Utils.h"
#include "CGAL_Binding.h"
#include "CGAL_Geometry_Simplifier.h"

static void *callback(enum mg_event event,
                      struct mg_connection *conn) {
  const struct mg_request_info *request_info = mg_get_request_info(conn);

  if (event == MG_NEW_REQUEST) {
    char post_data[1024000],
           todo[sizeof(post_data)], xmldata[sizeof(post_data)];
      int post_data_len;

      // Read POST data
      post_data_len = mg_read(conn, post_data, sizeof(post_data));

      // Parse form data. input1 and input2 are guaranteed to be NUL-terminated
      mg_get_var(post_data, post_data_len, "todo", todo, sizeof(todo));
      mg_get_var(post_data, post_data_len, "xmldata", xmldata, sizeof(xmldata));
      std::string testCGAL = Bind_CGAL("simplify",xmldata,post_data_len);
      const char* tosend = testCGAL.c_str();
      free_CGAL_Utils();

      mg_printf(conn, "HTTP/1.0 200 OK\r\n"
                "Content-Type: text/plain\r\n\r\n"
                
                
                "%s",

              
              
               tosend);
     
    // Mark as processed
    return (void*)"";
  } else {
    return NULL;
  }
}








 
/*
 * 
 */
int main(int argc, char** argv) {
    
    struct mg_context *ctx;
    const char *options[] = {"listening_ports", "8080", NULL};

    ctx = mg_start(&callback, NULL, options);
    getchar();  // Wait until user hits "enter"
    mg_stop(ctx);


    
    return 0; 
    
}

