%{
#include "y.tab.h"
#include<math.h>
%}

NUMBER [0-9]+|([0-9]*"."[0-9]+)

%%
{NUMBER} {yylval.dval=atof(yytext);
          return NUMBER;}


[\t]+ ;
\n|. return yytext[0];
%%








