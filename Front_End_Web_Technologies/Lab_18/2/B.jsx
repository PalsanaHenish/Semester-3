import { useState } from 'react';
import C from './C'

function B(props) {
    const [input, setInput] = useState("");
    return (
        <div>
            Component B
            <br />
            <label htmlFor="name">Name : </label>
            &nbsp;
            <input type="text" value={input} onChange={(e)=>{setInput(e.target.value)}} />
            <button onClick={()=>{props.setName(input)}}>Click Me</button>
            <C name={props.name} />
        </div>
    )
}

export default B
