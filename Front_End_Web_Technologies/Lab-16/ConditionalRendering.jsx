import React from 'react'

function ConditionalRendering({isDisplay}) {
  return (
    <>
        {(isDisplay)?<h1>Hii</h1>:<h1>Hello</h1>}
        {(isDisplay)?<h1>Hii</h1>:<h1>Hello</h1>}
    </>
  )
}

export default ConditionalRendering
