import React, { useState } from 'react'
import { useParams } from 'react-router-dom'

const SeatLayout = () => {
  const {id, date} = useParams()

  const [selectedSeats, setSelectedSeats] = useState([])

  return (
    <div>

    </div>
  )
}

export default SeatLayout