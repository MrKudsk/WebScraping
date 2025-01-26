#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "libxml/HTMLparser.h"
#include "libxml/xpath.h"

struct CURLResponse
{
  char *html;
  size_t size;
};

static size_t WriteHTMLCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t realsize = size * nmemb;
  struct CURLResponse *mem = (struct CURLResponse *)userp;
  
  char *ptr = realloc(mem->html, mem->size + realsize + 1);
  if(!ptr) {
    printf("Not enough memory available\n");
    return 0;
  }

  mem->html = ptr;
  memcpy(&(mem->html[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->html[mem->size] = 0;

  return realsize;
}

struct CURLResponse GetRequest(CURL *curl_handle, const char *url)
{
  CURLcode res;
  struct CURLResponse response;

  // initialize the response
  response.html = malloc(1);
  response.size = 0;

  // specify URL to GET
  curl_easy_setopt(curl_handle, CURLOPT_URL, url);
}

int main() {
  printf("Hello, World!\n");
  return 0;
}
