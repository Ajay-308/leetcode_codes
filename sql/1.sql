-- create testing day1 
 
create table test{
    'id' int(11) not null auto_increment  primary key,
    'name' varchar(255) not null,
    'age' int(3) not null,
}

-- to fetch 

select * from test;

--  for insert 
insert into test(1,'vikram',20);

-- updating table 
update test set name='bikas' where id=1;

-- alter table used to add , delete , or modify column which is presne int database

--> drop table -> delete table'
-- truncate table --> delete data inside table;

-- where clause use to filter data

select name from test where id >2

--  limit clause used to limit the number of rows in result set

select * from test limit 2;

--  order by clause used to sort the result set in ascending or descending order

select * from test order by id desc;

-- groub by clause used to group the result set by one or more column

select count(*) from test group by name;

-- having clause used to filter the result set by a group

select count(*) from test group by name having count(*)>1;

--  join clause used to combine rows from two or more tables bases on a related column betwenn them

select * from test join test2 on test.id = test2.id;

-- inner join clause used to retrun rows where there is at least one match in both tsblee

-- left join claused used to retrun all rows from the left table and the matched row from the right table;

-- right join 
--  full join

-- self join used to join a table to itself as like alias table name 

select a.name , b.name from test a , test b where a.id=b.id;

-- union clause used to combine the result set of two or more select statement

select name from test where id=1;
union
select name from test where id=2;

--  union all clause used to combine the result set of two or more select statement

select name from test where id=1;
union all
select name from test where id=2;

--  case clause used to create different output based on condition

select name ,age, case when age>18 then 'adult' else 'child' end as age_group from test;

-- intersect clause use to combine the result set of two or more select statement and resutn only the common rows

select name from test where id=1;
intersect
select name from test where id=2;

-- minus claus used to combine the result set of two or more select statement and retrun only the rows that are present in the first result set but not in the second result set

select name from test where id=1
minus
select name from test where id=2;

-- exist clause used to test for the existence of any record in a subquery

select name from test where exist (select name from test2 where test.id = test2.id);

--  not exist 

-- any clause used to compare a value to any value in a list

select name from test where age> any (select age from test2);


