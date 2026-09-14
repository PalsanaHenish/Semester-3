import { useState } from "react";
import Dashbord from "./Dashbord";
import Login from "./Login";

function AppContent() {
  const [currentUser, setCurrentUser] = useState(null);

  const handleLogIn = (userName)=>{
    setCurrentUser(userName);
  }

  const handleLogOut = ()=>{
    setCurrentUser(null);
  } 

  return (
    <>
      {currentUser ? (
        <Dashbord currentUser={currentUser} handleLogOut={handleLogOut} />
      ) : (
        <Login handleLogIn={handleLogIn} />
      )}
    </>
  );
}

export default AppContent;
