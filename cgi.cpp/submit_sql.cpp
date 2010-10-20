/* 
   This file is part of GNU Sqltutor
   Copyright (C) 2008  Free Software Foundation, Inc.
   Contributed by Ales Cepek <cepek@gnu.org>
 
   GNU Sqltutor is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   GNU Sqltutor is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with GNU Sqltutor.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "sqltutor.h"

void SQLtutor::submit_sql(pqxx::work& tran)
{  
  if (empty(sql)) return;

  check_answer(tran);

  Table errt(1);
  errt.th(t_wrong_answer);
  bool error = false;
  if (sql_result_columns != sql_tutor_columns)
    {
      std::ostringstream ostr;
      ostr << t_unmatched_cols << " " << sql_result_columns << ", " 
           << t_should_be      << " " << sql_tutor_columns;
      errt << ostr.str();
      error = true;
    }
  if (sql_result_size != sql_tutor_size)
    {
      std::ostringstream ostr;
      ostr << t_unmatched_rows << " " << sql_result_size << ", "
           << t_should_be      << " " << sql_tutor_size;
      errt << ostr.str();
      error = true;
    }
  if (error)
    {
      form << errt << Par();
      return;
    }

  if (correct_answer)
    {
      form << "<p><b>" + t_correct_answer + "</b><br/>";
      if (!first_permutation) form << t_permutation << "</p>";
      sql_checked = "yes";
    }
  else
    {
      form << "<p><b>" + t_wrong_answer + "</b></p>";
    }
}



