# Write your MySQL query statement below
select b.name
from
employee a
left join
employee b
on a.managerId=b.id
group by b.id
having count(b.id)>=5
 ;
