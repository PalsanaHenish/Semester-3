import React from 'react'

function SignIn() {
  return (
    <div className='container mt-5'>
        <div className='row justify-content-center'>
            <div className='col-3 text-end'>
                <label>Name</label>
            </div>
            <div className='col-5'>
                <input type='text' style={{width:"300px"}}/>
            </div>
        </div>  

        <div className='row justify-content-center mt-3'>
            <div className='col-3 text-end'>
                <label>Email</label>
            </div>
            <div className='col-5'>
                <input type='email' style={{width:"300px"}}/>
            </div>
        </div> 

        <div className='row justify-content-center mt-3'>
            <div className='col-3 text-end'>
                <label>Password</label>
            </div>
            <div className='col-5'>
                <input type='password' style={{width:"300px"}}/>
            </div>
        </div>

        <div className='row justify-content-center mt-3'>
            <div className='col-2'>
                <input type='button' value='Submit' style={{width:"100px"}}/>
            </div>
        </div>
    </div>  
  )
}

export default SignIn
