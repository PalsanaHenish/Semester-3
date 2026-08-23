import React from 'react'

function Navbar() {
  return (
    <>
        <h1 class="display-6" align="center">
          About <mark>India </mark>
        </h1>
      <div class="Navbar navbar navbar-expand-lg bg-dark text-light d-flex justify-content-center">
          <a href="./index.html" class="text-light px-2 text-decoration-none">
            Home
          </a>
          <a href="./About.html" class="text-light px-2 text-decoration-none">
            About
          </a>

          <li class="nav-item dropdown">
            <a
              class="nav-link dropdown-toggle nav-link active"
              href="#"
              role="button"
              data-bs-toggle="dropdown"
              aria-expanded="false"
            >
              Places
            </a>
            <ul class="dropdown-menu">
              <li>
                <a class="dropdown-item" href="./Gujarat.html">
                  Gujarat
                </a>
              </li>
              <li>
                <a class="dropdown-item" href="./Rajasthan.html">
                  Rajashthan
                </a>
              </li>
              <li>
                <a class="dropdown-item" href="./Maharastra.html">
                  Maharashtra
                </a>
              </li>
              <li>
                <a class="dropdown-item" href="./Uttarpradesh.html">
                  Uttarpradesh
                </a>
              </li>
            </ul>
          </li>
          <a
            href="./Travel_info.html"
            class="text-light px-2 text-decoration-none"
          >
            Travel Info
          </a>
          <a href="./Contact.html" class="text-light px-2 text-decoration-none">
            Contact
          </a>
        </div>
    </>
  )
}

export default Navbar
