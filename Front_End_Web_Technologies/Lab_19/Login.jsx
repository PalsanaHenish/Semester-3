import { useState } from "react";

function Login({handleLogIn}) {
    const [userName, setUserName] = useState('');
    const [password, setPassword] = useState('');

  return (
    <>
      <form onSubmit={()=>{
        if("Admin" == userName && "1234" == password){
            alert("Login Successfully!");
            handleLogIn(userName);
        }
        else{
            alert("Incorrect Username or Password!");
        }
      }}>
        <label htmlFor="name">Username : </label>
        <input type="text" value={userName} onChange={(e)=>{setUserName(e.target.value)}} />
        <br /><br />
        <label htmlFor="password">Password : </label>
        <input type="text" value={password} onChange={(e)=>{setPassword(e.target.value)}} />
        <br /><br />
        <input type="submit" value="Submit" />
      </form>
    </>
  )
}

export default Login
