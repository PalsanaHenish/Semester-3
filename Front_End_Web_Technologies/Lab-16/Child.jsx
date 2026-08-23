import React from 'react'

function Parent({name, age, gender, city}) {
  return (
    <div>
      <h1>Name : {name}</h1>
      <h1>Age : {age}</h1>
      <h1>Gender : {gender}</h1>
      <h1>City : {city}</h1>
    </div>
  )
}

function Child(){
    return (
        <>
            <Parent name="Henish" age="19" gender="Male" city="Babra"/>
            <br /><br />
            <Parent name="Dhairya" age="18" gender="Male" city="Rajkot"/>
            <br /><br />
            <Parent name="Utsav" age="19" gender="Male" city="Jamnagar"/>
        </>
    );
}

export default Child
