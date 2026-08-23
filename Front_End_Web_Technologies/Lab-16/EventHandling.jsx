import React, { useState } from 'react'

function EventHandling() {
    const [top, setTop] = useState(0);
    const [left, setLeft] = useState(0);

  return (
    <div>
        <button onClick={()=>{setTop(top + 200)}}>Top</button>
      <h1>
        {top}
      </h1>
    </div>
  )

        
}

export default EventHandling
