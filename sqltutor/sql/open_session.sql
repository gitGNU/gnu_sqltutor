CREATE OR REPLACE FUNCTION open_session
(
      IN  login_      varchar(20),
      IN  password_   varchar(20),
      IN  points_min_ integer,
      IN  points_max_ integer,
      IN  dataset_    varchar(12),
      IN  help_       boolean,
      IN  host_       inet,
      OUT session_id_ integer,
      OUT hash_       char(32)
) 
AS $$
DECLARE
   time_ timestamp = now();
BEGIN
   INSERT INTO sessions (login,    password,  points_min,  points_max,
                         dataset,  help,      host,        time ) 
                 VALUES (login_,   password_, points_min_, points_max_,
                         dataset_, help_,     host_,       time_);

   SELECT INTO session_id_ lastval();
   hash_ = md5(time_);
END;
$$ LANGUAGE plpgsql;
