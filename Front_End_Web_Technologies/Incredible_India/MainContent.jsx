import React from 'react'

function MainContent() {
  return (
    <>
      <hr />
        <div class="image1">
          <img
            src="https://i.pinimg.com/1200x/07/70/a5/0770a579c6dc398fa7bcd311104b1118.jpg"
            width="350"
          />
        </div>
        <div class="text">
          A South Asian country known for its immense diversity, rich history,
          and vibrant culture, being the world's most populous democracy and
          seventh-largest nation by area.
        </div>

        <ul>
          <li>
            Geographics & Demographics: Located in South Asia, bordered by the
            Indian Ocean and several countries, it features varied landscapes,
            from mountains to deserts, with New Delhi as its capital and Mumbai
            as its largest city.
          </li>
          <li>
            Culture & Heritage: A secular nation with a mosaic of cultures,
            religions (Hinduism, Islam, Sikhism, etc.), and languages,
            celebrated through festivals like Diwali and traditions like yoga.
          </li>
          <li>
            History & Governance: Gained independence in 1947 and is the world's
            largest democracy, emphasizing "Unity in Diversity".
          </li>
          <li>
            Economy & Innovation: A rapidly growing economy driven by
            agriculture, technology, and services, known for ancient
            contributions to mathematics, medicine, and philosophy.
          </li>
          <li>
            Landmarks: Home to iconic sites such as the Taj Mahal, the Ganges
            River, and numerous UNESCO World Heritage Sites.
          </li>
        </ul>

        <h1>History & Background</h1>
        <div class="p2">
          <img
            src="https://i.pinimg.com/1200x/3c/5f/d5/3c5fd58b76dc39c1becb5c739b801fe7.jpg"
            width="400"
          />
          <img src="./photos/historycollage.jpg" height="500" width="400" />
        </div>
        <div class="text">
          India's history spans from the ancient Indus Valley Civilization (c.
          2500 BCE) through Vedic, Maurya, Gupta, Delhi Sultanate, and Mughal
          empires, leading to British colonization and eventual independence in
          1947.
        </div>

        <h2>Ancient Roots & Empires:</h2>

        <ul>
          <li>
            Indus Valley Civilization: One of the world's earliest urban
            cultures, flourishing around 2500 BCE.
          </li>
          <li>
            Vedic Period: Saw the composition of the Vedas and the formation of
            early Hindu philosophies and social structures (c. 1500–500 BCE).
          </li>
          <li>
            Rise of Religions: Gave rise to Jainism and Buddhism around the 6th
            century BCE, challenging older traditions.
          </li>
          <li>
            Empires: Dominated by powerful dynasties like the Mauryas (including
            Ashoka) and Guptas, followed by Islamic Sultanates and the Mughals,
            who built significant cultural and architectural legacies.
          </li>
        </ul>

        <h2>Colonial Era & Independence:</h2>

        <ul>
          <li>
            British Rule: Began with the East India Company and became direct
            administration in 1858, unifying the subcontinent politically but
            under foreign control for nearly a century.
          </li>
          <li>
            Independence: Achieved on August 15, 1947, after a prolonged
            struggle, ushering in the era of the Republic of India.
          </li>
        </ul>

        <h2>Modern India:</h2>

        <ul>
          <li>
            Challenges & Growth: The newly independent nation faced immense
            challenges, including partition, poverty, and conflicts, but
            transformed into a fast-growing G20 economy.
          </li>
          <li>
            Democracy: Became the world's largest democracy, navigating
            multi-party politics, significant social issues like casteism, and
            territorial disputes.
          </li>
          <li>
            Global Role: Evolved into a nuclear power and a significant player
            in global affairs, known for its large, young population and diverse
            culture.
          </li>
        </ul>

        <h1>Culture & Lifestyle:</h1>

        <ul>
          <li>
            Festivals: India celebrates vibrant festivals like Diwali, Holi,
            Eid, and Christmas, reflecting its rich cultural tapestry.
          </li>
          <li>
            Cuisine: Indian cuisine is famous for its spices and flavors, with
            each region offering unique dishes and street food.
          </li>
          <li>
            Art & Music: Traditional music, dance forms like Bharatanatyam and
            Kathak, and colorful art are integral to Indian culture.
          </li>
        </ul>
        <div class="table">
          <h1>Climate Information about India</h1>

          <table border="1">
            <thead>
              <tr class="row">
                <th class="col">Season</th>
                <th class="col">Months</th>
                <th class="col">Temperature(in celcius)</th>
                <th class="col">Tourist Crowd Level</th>
              </tr>
            </thead>
            <tbody>
              <tr class="row">
                <td class="col">Winter</td>
                <td class="col">December-February</td>
                <td class="col">10-25</td>
                <td class="col">High</td>
              </tr>
              <tr class="row">
                <td class="col">Summer</td>
                <td class="col">March-June</td>
                <td class="col">30-45</td>
                <td class="col">Medium</td>
              </tr>
              <tr class="row">
                <td class="col">Monsoon</td>
                <td class="col">June-September</td>
                <td class="col">10-30</td>
                <td class="col">High</td>
              </tr>
            </tbody>
          </table>
        </div>
    </>
  )
}

export default MainContent
